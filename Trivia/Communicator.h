#pragma once
#include "LoginRequestHandler.h"
#include "RequestHandlerFactory.h"
#include <map>
#include <thread>
#include "Helper.h"

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

	SOCKET m_serverSocket;
	std::map < SOCKET, IRequestHandler* > m_clients;
	RequestHandlerFactory& m_handleFactory;
};