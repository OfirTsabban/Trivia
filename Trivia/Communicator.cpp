#include "Communicator.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonResponsePacketSerializer.h"
#include "IRequestHandler.h"
#include <exception>
#include <iostream>
#include <string>
#include <numeric>

static const unsigned short PORT = 12345;
static const unsigned int IFACE = 0;

Communicator::Communicator(RequestHandlerFactory& handleFactory) : m_handleFactory(handleFactory)
{
	this->m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");

}

Communicator::~Communicator()
{
	try {
		closesocket(m_serverSocket);
	}
	catch(...) {}
}

void Communicator::startHandleRequests()
{
	bindAndListen();

	while (true)
	{
		// the main thread is only accepting clients
		// and add then to the list of handlers
		TRACE("Waiting for client...");
		acceptClient();
	}
}

void Communicator::bindAndListen()
{
	struct sockaddr_in sa = { 0 };
	sa.sin_port = htons(PORT);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = IFACE;
	// again stepping out to the global namespace
	if (::bind(m_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");
	TRACE("binded");

	if (::listen(m_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	TRACE("listening...");
}

void Communicator::acceptClient()
{
	SOCKET client_socket = accept(m_serverSocket, NULL, NULL);
	if (client_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__);

	TRACE("Client accepted !");
	// create new thread for client	and detach from it
	std::thread tr(&Communicator::handleNewClient, this, client_socket);
	tr.detach();

	LoginRequestHandler* clientHandler = m_handleFactory.createLoginRequestHandler();
	m_clients.insert(std::pair<SOCKET, IRequestHandler*>(client_socket, clientHandler));
}

void Communicator::handleNewClient(SOCKET client_socket)
{	
	int id = 0;
	do
	{
		/*std::unique_lock<std::mutex> lock(this->commMutex);*/
		id = Helper::getMessageTypeCode(client_socket);
		if (id != 200)
		{
			std::string msg = Helper::getStringPartFromSocket(client_socket, 1024);
			time_t recivalTime = std::time(nullptr);
			unsigned char* buffer = new unsigned char[(msg.length() + 1)];
			std::copy(msg.begin(), msg.end(), buffer);
			buffer[msg.length()] = 0;
			RequestInfo reqInfo = { id,recivalTime,buffer };
			IRequestHandler* handle = m_clients[client_socket];//handle will be the specified handler to the socket
			RequestResult reqRes = handle->handleRequest(reqInfo, client_socket);
			m_clients[client_socket] = reqRes.newHandler;
			std::string s = reinterpret_cast<char*>(reqRes.response);
			Helper::sendData(client_socket, s);
		}
	} while (id != 200);//if not exit
	
	std::cout << "Client left: " << client_socket << std::endl;
	closesocket(client_socket);
}
