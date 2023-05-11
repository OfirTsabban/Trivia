#include "LoginManager.h"

void LoginManager::signup(std::string name, std::string password, std::string email, std::string street, int apt, std::string city, std::string prefix, std::string number, std::string yearBorn)
{
	if (m_database->doesUserExist(name))
	{
		std::cout << "user already exists!" << std::endl; //need to add exeptions
	}
	else
	{
		m_database->addNewUser(name, password, email, street, apt, city, prefix, number, yearBorn);
		m_loggedUsers.push_back(LoggedUser(name));
	}
}

void LoginManager::login(std::string name, std::string password)
{
	if (std::find(m_loggedUsers.begin(), m_loggedUsers.end(), LoggedUser(name)) != m_loggedUsers.end())
	{
		std::cout << "user already logged in" << std::endl; //need to add exeptions
	}
	else if(!m_database->doesPasswordMatch(name, password))
	{
		std::cout << "password did not match user..." << std::endl; //need to add exeptions
	}
	else
	{
		m_loggedUsers.push_back(LoggedUser(name));
	}
}

void LoginManager::logout(std::string name)
{
	for (auto it = m_loggedUsers.begin(); it != m_loggedUsers.end(); it++)
	{
		if (it->getUsername() == name)
		{
			m_loggedUsers.erase(it);
			return;
		}
	}
}