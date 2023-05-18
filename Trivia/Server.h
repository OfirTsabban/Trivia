#pragma once
#include "Communicator.h"
#include "SqliteDatabase.h"
#include "RequestHandlerFactory.h"
#include <iostream>

class Server
{
public:
	Server();
	void run();

private:
	SqliteDatabase m_database;
	RequestHandlerFactory m_hanlderFactory;
	Communicator m_communicator;
};