#include "SqliteDatabase.h"

int callBackGlobal(void* data, int argc, char** argv, char** azColName)
{
	std::string& is_exist = *((std::string*)data);
	for (int i = 0; i < argc; i++)
	{
		is_exist += argv[i];
		is_exist += "|";
	}
	return 0;
}

bool SqliteDatabase::open()
{
	std::string dbFileName = "TriviaDB.sqlite";

	int fileExist = _access(dbFileName.c_str(), 0);
	int res = sqlite3_open(dbFileName.c_str(), &this->_db);

	if (res != SQLITE_OK)
	{
		this->_db = nullptr;
		return false;
	}

	if (fileExist == -1)
	{
		const char* sqlStatement = "CREATE TABLE IF NOT EXISTS USERS(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, USERNAME TEXT NOT NULL, PASSWORD TEXT NOT NULL, EMAIL TEXT NOT NULL, STREET TEXT NOT NULL, APT INT NOT NULL, CITY TEXT NOT NULL, PREFIX TEXT NOT NULL, NUMBER TEXT NOT NULL, YEARBORN TEXT NOT NULL);";
		char* errMessage = nullptr;
		int res = sqlite3_exec(this->_db, sqlStatement, nullptr, nullptr, &errMessage);
		if (res != SQLITE_OK)
		{
			std::cout << "error creating Users" << std::endl;
			return false;
		}

	}
}

bool SqliteDatabase::doesUserExist(std::string name)
{
	std::string data = "";

	std::string sqlStatement = "SELECT * FROM Users WHERE USERNAME = " + name + ";";
	char* errMessage = nullptr;
	int res = sqlite3_exec(&this->_db, sqlStatement.c_str(), callBackGlobal, &data, &errMessage);
	if (res != SQLITE_OK) {
		std::cout << std::endl << "error" << std::endl;
	}

	return data.length();
}