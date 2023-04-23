#include "Communicator.h"
#include <exception>
#include <iostream>
#include <string>
#include <numeric>

static const unsigned short PORT = 12345;
static const unsigned int IFACE = 0;

void Communicator::startHandleRequests()
{
	bindAndListen();

	while (true)
	{
		// the main thread is only accepting clients
		// and add then to the list of handlers
		TRACE("accepting client...");
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

	LoginRequestHandler* temp;
	
	m_clients.emplace(std::make_pair(client_socket, temp));
}

void Communicator::handleNewClient(SOCKET client_socket)
{
	Helper::sendData(client_socket, "Hello");

	//not finished
}
