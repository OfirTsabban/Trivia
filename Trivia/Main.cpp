#include "Server.h"
#include "SqliteDatabase.h"

int main()
{
	WSADATA wsa;

	SqliteDatabase* db = new SqliteDatabase();

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}	

	Server serv;
	serv.run();
}