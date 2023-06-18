#include "LoggedUser.h"

LoggedUser::LoggedUser(const std::string& name, const SOCKET userSocket)
{
	this->m_username = name;
	this->m_userSocket = userSocket;
}

LoggedUser::LoggedUser(const LoggedUser& other)
{
	this->m_username = other.m_username;
	this->m_userSocket = other.m_userSocket;
}

std::string LoggedUser::getUsername()
{
	return this->m_username;
}

SOCKET LoggedUser::getUserSocket()
{
	return this->m_userSocket;
}

LoggedUser LoggedUser::operator=(LoggedUser const& other)
{
	this->m_username = other.m_username;
	this->m_userSocket = other.m_userSocket;
	return *this;
}

bool LoggedUser::operator==(LoggedUser const& other)
{
	return this->m_username == other.m_username;
}

bool LoggedUser::operator<(const LoggedUser& other) const
{
	return this->m_username.length() < other.m_username.length();
}