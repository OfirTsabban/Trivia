#pragma once
#include "IDatabase.h"
#include <io.h>


class SqliteDatabase : public IDatabase
{
public:
	bool open();
	virtual bool doesUserExist(std::string name);
	virtual bool doesPasswordMatch(std::string name, std::string password);
	virtual void addNewUser(std::string name, std::string password, std::string email);

private:
	sqlite3* _db;
};