#pragma once
#include "IDatabase.h"

class SqliteDatabase : public IDatabase
{
public:
	virtual bool doesUserExist(std::string name);
	virtual bool doesPasswordMatch(std::string name, std::string password);
	virtual void addNewUser(std::string name, std::string password, std::string email);
};