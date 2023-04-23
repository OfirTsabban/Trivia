#include "Server.h"

void Server::run()
{
	std::string input = "";

	std::thread t_connector(&Communicator::startHandleRequests, this);
	t_connector.detach();

	while (true)
	{
		std::cin >> input;
		if (input == "EXIT")
			break;
	}
}
