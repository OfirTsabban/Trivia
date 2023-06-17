#pragma once
#include <iostream>
#include "Helper.h"

class LoggedUser
{
public:
	LoggedUser(const std::string& name, const SOCKET userSocket);
	std::string getUsername();
	SOCKET getUserSocket();

	bool operator==(LoggedUser const& other);

private:
	std::string m_username;
	SOCKET m_userSocket;
};