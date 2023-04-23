#include "Server.h"

#pragma comment(lib, "Ws2_32.lib")

int main()
{
	WSADATA wsa;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}
	Server serv;
	serv.run();
}