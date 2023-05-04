#pragma once
#include <map>
#include <thread>
#include "IRequestHandler.h"
#include "LoginRequestHandler.h"
#include "Helper.h"

class Communicator 
{
public:
	Communicator();
	~Communicator();
	void startHandleRequests();

private:
	void bindAndListen();
	void acceptClient();
	void handleNewClient(SOCKET client_socket);

	SOCKET m_serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;
};