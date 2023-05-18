#include "LoggedUser.h"

LoggedUser::LoggedUser(const std::string& name)
{
	this->m_username = name;
}

std::string LoggedUser::getUsername()
{
	return this->m_username;
}

bool LoggedUser::operator==(LoggedUser const& other)
{
	return this->m_username == other.m_username;
}
