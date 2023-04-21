#pragma once
#include "IRequestHandler.h"
#include "Helper.h"
#include <map>

class Communicator 
{
public:
	void startHandleRequests();

private:
	void bindAndListen();
	void handleNewClient(SOCKET client_socket);

	SOCKET m_serverSocket;
	std::map <SOCKET, IRequestHandler> m_clients;
};