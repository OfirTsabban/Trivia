#pragma once
#include <iostream>

class LoggedUser
{
public:
	LoggedUser(const std::string& name);
	std::string getUsername();

	bool operator==(LoggedUser const& other);

private:
	std::string m_username;
};