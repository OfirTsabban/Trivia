#pragma once
#include "IDatabase.h"
#include <io.h>
#include <iostream>


class SqliteDatabase : public IDatabase
{
public:
	SqliteDatabase();
	~SqliteDatabase() = default;

	void addQuestions();
	void addNewQuestion(std::string question, std::string first, std::string second, std::string third, std::string fourth, std::string right);
	
	virtual bool doesUserExist(std::string name);
	virtual bool doesPasswordMatch(std::string name, std::string password);
	virtual void addNewUser(std::string name, std::string password, std::string email, std::string street, std::string apt, std::string city, std::string prefix, std::string number, std::string yearBorn);
	virtual std::list<Question> getQuestions(int num);
	virtual float getPlayerAverageAnswerTime(std::string name);
	virtual int getNumOfCorrectAnswers(std::string name);
	virtual int getNumOfTotalAnswers(std::string name);
	virtual int getNumOfPlayerGames(std::string name);
	virtual int getPlayerScore(std::string name);
	virtual std::vector<std::string> getHighScores();

private:
	sqlite3* _db;
};