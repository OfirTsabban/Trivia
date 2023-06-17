#pragma once
#include <iostream>
#include <vector>
#include <mutex>
#include "LoggedUser.h"
#include "SqliteDatabase.h"
#include "ExceptionHandler.h"

using std::vector;
using std::mutex;

class LoginManager
{
public:
	LoginManager(IDatabase* db);
	~LoginManager() = default;
	void signup(std::string name, std::string password, std::string email, std::string street, std::string apt, std::string city, std::string prefix, std::string number, std::string yearBorn, SOCKET socket);
	void login(std::string name, std::string password, SOCKET socket);
	void logout(std::string name);

private:
	bool checkName(std::string username);//true - valid username, false - username contains numbers or digits

	IDatabase* m_database;
	vector<LoggedUser> m_loggedUsers;
	mutex usersMutex;
};