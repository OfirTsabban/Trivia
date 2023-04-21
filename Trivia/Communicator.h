#pragma once
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
	std::map <SOCKET, int> m_clients;
};