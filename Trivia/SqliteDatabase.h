#pragma once
#include "IDatabase.h"
#include <io.h>
#include <iostream>


class SqliteDatabase : public IDatabase
{
public:
	bool open();
	virtual bool doesUserExist(std::string name);
	virtual bool doesPasswordMatch(std::string name, std::string password);
	virtual void addNewUser(std::string name, std::string password, std::string email, std::string street, int apt, std::string city, std::string prefix, std::string number, std::string yearBorn);

private:
	sqlite3* _db;
};