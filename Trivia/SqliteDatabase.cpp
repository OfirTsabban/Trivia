#include "SqliteDatabase.h"
#include "ExceptionHandler.h"
#include <string>

int callBackGetQuestions(void* data, int argc, char** argv, char** azColName)
{
	std::list<Question>& Questions = *((std::list<Question>*)data);
	Question newQ(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
	Questions.push_back(newQ);

	return 0;
}

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

SqliteDatabase::SqliteDatabase()
{
	std::string dbFileName = "TriviaDB.sqlite";
	int fileExist = _access(dbFileName.c_str(), 0);
	int res = sqlite3_open(dbFileName.c_str(), &this->_db);

	if (res != SQLITE_OK)
	{
		this->_db = nullptr;
		throw ExceptionHandler("Error opening db");
	}

	if (fileExist == -1)
	{
		const char* sqlStatement = "CREATE TABLE IF NOT EXISTS USERS(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, USERNAME TEXT NOT NULL, PASSWORD TEXT NOT NULL, EMAIL TEXT NOT NULL, STREET TEXT NOT NULL, APT INT NOT NULL, CITY TEXT NOT NULL, PREFIX TEXT NOT NULL, NUMBER TEXT NOT NULL, YEARBORN TEXT NOT NULL);";
		char* errMessage = nullptr;
		int res = sqlite3_exec(this->_db, sqlStatement, nullptr, nullptr, &errMessage);
		if (res != SQLITE_OK)
		{
			std::cout << "error creating Users" << std::endl;
			throw ExceptionHandler("Error opening users table");
		}
		sqlStatement = "CREATE TABLE IF NOT EXISTS QUESTIONS(QUESTION TEXT NOT NULL, FIRSTANSWER TEXT NOT NULL, SECONDANSWER TEXT NOT NULL, THIRDANSWER TEXT NOT NULL, FOURTHANSWER TEXT NOT NULL, RIGHTANSWER INT NOT NULL);";
		res = sqlite3_exec(this->_db, sqlStatement, nullptr, nullptr, &errMessage);
		if (res != SQLITE_OK)
		{
			std::cout << "error creating Questions" << std::endl;
			throw ExceptionHandler("Error opening questions table!");
		}
	}
}

bool SqliteDatabase::doesUserExist(std::string name)
{
	std::string data = "";

	std::string sqlStatement = "SELECT * FROM Users WHERE USERNAME = '" + name + "';";
	char* errMessage = nullptr;
	int res = sqlite3_exec(this->_db, sqlStatement.c_str(), callBackGlobal, &data, &errMessage);
	if (res != SQLITE_OK) {
		std::cout << std::endl << "error" << std::endl;
	}

	return data.length();
}

bool SqliteDatabase::doesPasswordMatch(std::string name, std::string password)
{
	std::string data = "";

	std::string sqlStatement = "SELECT * FROM Users WHERE USERNAME = '" + name + "' AND PASSWORD = '" + password + "';";
	char* errMessage = nullptr;
	int res = sqlite3_exec(this->_db, sqlStatement.c_str(), callBackGlobal, &data, &errMessage);
	if (res != SQLITE_OK) {
		std::cout << std::endl << "error" << std::endl;
	}

	return data.length();
}

void SqliteDatabase::addNewUser(std::string name, std::string password, std::string email, std::string street, std::string apt, std::string city, std::string prefix, std::string number, std::string yearBorn)
{
	std::string sqlStatement = "INSERT INTO Users(USERNAME, PASSWORD, EMAIL, STREET, APT, CITY, PREFIX, NUMBER, YEARBORN) VALUES('" + name + "', '" + password + "', '" + email + "', '" + street + "', " + apt + ", '" + city + "', '" + prefix + "', '" + number + "', '" + yearBorn + "'); ";
	char* errMessage = nullptr;
	int res = sqlite3_exec(this->_db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK)
	{
		std::cout << "error" << std::endl;
	}
}

std::list<Question> SqliteDatabase::getQuestions(int num)
{
	std::list<Question> allQuestions;
	std::string sqlStatement = "SELECT * FROM QUESTIONS ORDER BY RANDOM() LIMIT " + std::to_string(num) + ";";
	char* errMessage = nullptr;
	int res = sqlite3_exec(this->_db, sqlStatement.c_str(), callBackGetQuestions, &allQuestions, &errMessage);
	if (res != SQLITE_OK)
	{
		std::cout << "error" << std::endl;
	}

	return allQuestions;
}

void SqliteDatabase::addQuestions()
{	
	addNewQuestion("During Peter and the Giant Chicken�s second fight, a scene from what movie is parodied at the end?","Dont Deal With the Zohan", "Indiana Jones: The Raiders of the Lost Ark", "Inception", "Dora the Explorar in the Big City", 2);
	addNewQuestion("Which Family Guy character went to Brown University?", "Brian", "Lois", "Meg", "Stewie", 1);
	addNewQuestion("What famous rocker did Lois once sleep with?", "Bon Jovi", "David Bowie", "John Lennon", "Gene Simmons", 4);
	addNewQuestion("Why is Peter always fighting Ernie, the giant chicken?", "Ernie gave Peter an expired coupon", "Ernie stole his chicken", "Peter just hates him for no reason", "Ernie lectured Peter about being vegan", 1);
	addNewQuestion("What did Peter change Meg�s name to on her birth certificate?", "Meggie", "Megan", "Megatron", "Megalean", 3);
	addNewQuestion("What lives in Chris�s closet?", "a barbie doll", "a crocodile", "Meg", "an evil monkey", 4);
	addNewQuestion("Who caused the big bang in the episode �The Big Bang Theory�?", "Peter", "Quagmire", "Stewie", "Chris", 3);
	addNewQuestion("Which Family Guy character is a brainwashed Russian sleeper agent?", "Lois", "Peter", "Adam West", "Nicole", 3);
	addNewQuestion("When Peter finds out his house isn�t part of the United States, what does he name his property?", "Peterland", "Petoria", "Griffinoa", "Fatherland", 2);
	addNewQuestion(" Who burned The Drunken Clam to the ground?", "God", "Peter", "the Bar Tender", "Chris", 1);
}
void SqliteDatabase::addNewQuestion(std::string question, std::string first, std::string second, std::string third, std::string fourth, int right)
{
	std::string sqlStatement = "INSERT INTO Questions(QUESTION, FIRSTANSWER, SECONDANSWER, THIRDANSWER,FOURTHANSWER) VALUES('" + question + ", " + first + ", " + second + ", " + third + ", " + fourth + ", " + std::to_string(right) + "'); "; 
	char* errMessage = nullptr; 
	int res = sqlite3_exec(this->_db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK)
	{
		std::cout << "error" << std::endl;
	}
}
