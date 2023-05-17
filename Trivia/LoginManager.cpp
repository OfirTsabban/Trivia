#include "LoginManager.h"
#include <vector>

LoginManager::LoginManager(IDatabase* db) :m_database()
{
}

void LoginManager::signup(std::string name, std::string password, std::string email, std::string street, int apt, std::string city, std::string prefix, std::string number, std::string yearBorn)
{
	if (m_database->doesUserExist(name))
	{
		std::cout << "user already exists!" << std::endl;
		throw ExceptionHandler("Error - user already exists!");
	}
	else
	{
		m_database->addNewUser(name, password, email, street, apt, city, prefix, number, yearBorn);
		m_loggedUsers.push_back(LoggedUser(name));
	}
}

void LoginManager::login(std::string name, std::string password)
{
	LoggedUser user(name);
	if (std::find(m_loggedUsers.begin(), m_loggedUsers.end(), user) != m_loggedUsers.end())
	{
		std::cout << "user already logged in" << std::endl;
		throw ExceptionHandler("Error! User Already logged in!");
	}
	else if(!m_database->doesPasswordMatch(name, password))
	{
		std::cout << "password did not match user..." << std::endl;
		throw ExceptionHandler("Error! Password did not match the user you looked for!");
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

bool LoginManager::checkName(std::string username)
{
	int i = 0;

	for (i = 0; i < username.length(); i++)
	{
		if (!isalnum(username[i]))
		{
			return false;
		}
	}

	return true;
}
