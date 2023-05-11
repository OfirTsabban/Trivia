#pragma once
#include <iostream>

class LoggedUser
{
public:
	LoggedUser(std::string name);
	std::string getUsername();

	bool operator==(LoggedUser const& other);

private:
	std::string m_username;
};