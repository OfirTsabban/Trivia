#pragma once
#include <iostream>
#include "sqlite3.h"
#include "sqlite3ext.h"

class IDatabase
{
public:
	virtual bool doesUserExist(std::string name) = 0;
	virtual bool doesPasswordMatch(std::string name, std::string password) = 0;
	virtual void addNewUser(std::string name, std::string password, std::string email) = 0;
};