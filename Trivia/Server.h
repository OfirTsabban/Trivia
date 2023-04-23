#pragma once
#include "Communicator.h"
#include <iostream>

class Server
{
public:
	void run();

private:
	Communicator m_communicator;
};