#include "LoggedUser.h"

LoggedUser::LoggedUser(const std::string& name, const SOCKET userSocket)
{
	this->m_username = name;
	this->m_userSocket = userSocket;
}

std::string LoggedUser::getUsername()
{
	return this->m_username;
}

SOCKET LoggedUser::getUserSocket()
{
	return this->m_userSocket;
}

bool LoggedUser::operator==(LoggedUser const& other)
{
	return this->m_username == other.m_username;
}
