#pragma once
#include "LoginRequestHandler.h"
#include "RequestHandlerFactory.h"
#include <map>
#include <thread>
#include <mutex>
#include "Helper.h"

using std::mutex;

class IRequestHandler;//tal helped <3
class RequestHandlerFactory;

class Communicator 
{
public:
	Communicator(RequestHandlerFactory& handleFactory);
	~Communicator();
	void startHandleRequests();

private:
	void bindAndListen();
	void acceptClient();
	void handleNewClient(SOCKET client_socket);

	mutex commMutex;
	SOCKET m_serverSocket;
	std::map < SOCKET, IRequestHandler* > m_clients;
	RequestHandlerFactory& m_handleFactory;
};