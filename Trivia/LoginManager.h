#pragma once
#include <vector>
#include "LoggedUser.h"
#include "SqliteDatabase.h"
#include "ExceptionHandler.h"

class LoginManager
{
public:
	void signup(std::string name, std::string password, std::string email, std::string street, int apt, std::string city, std::string prefix, std::string number, std::string yearBorn);
	void login(std::string name, std::string password);
	void logout(std::string name);

private:
	IDatabase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
};