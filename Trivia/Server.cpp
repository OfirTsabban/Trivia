#include "Server.h"

void Server::run()
{
	std::string input = "";

	try {
		std::thread t_connector(&Communicator::startHandleRequests, m_communicator);
		t_connector.detach();

		while (true)
		{
			std::cin >> input;
			if (input == "EXIT")
				break;
		}
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
}
