#pragma once
#include <iostream>
#include "Helper.h"

class LoggedUser
{
public:
	LoggedUser(const std::string& name, const SOCKET userSocket);
	LoggedUser(const LoggedUser& other);
	std::string getUsername();
	SOCKET getUserSocket();

	LoggedUser operator=(LoggedUser const& other);
	bool operator==(LoggedUser const& other);
	bool operator<(const LoggedUser& other) const;

private:
	std::string m_username;
	SOCKET m_userSocket;
};