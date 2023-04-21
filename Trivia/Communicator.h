#pragma once
#include "IRequestHandler.h"
#include "LoginRequestHandler.h"
#include "Helper.h"
#include <map>
#include <thread>

class Communicator 
{
public:
	void startHandleRequests();

private:
	void bindAndListen();
	void acceptClient();
	void handleNewClient(SOCKET client_socket);

	SOCKET m_serverSocket;
	std::map <SOCKET, IRequestHandler*> m_clients;
};