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
	
	virtual bool doesUserExist(std::string name) override;
	virtual bool doesPasswordMatch(std::string name, std::string password)override;
	virtual void addNewUser(std::string name, std::string password, std::string email, std::string street, std::string apt, std::string city, std::string prefix, std::string number, std::string yearBorn)override;
	virtual std::list<Question> getQuestions(int num)override;
	virtual float getPlayerAverageAnswerTime(std::string name)override;
	virtual int getNumOfCorrectAnswers(std::string name)override;
	virtual int getNumOfTotalAnswers(std::string name)override;
	virtual int getNumOfPlayerGames(std::string name)override;
	virtual int getPlayerScore(std::string name)override;
	virtual std::vector<std::string> getHighScores()override;

private:
	sqlite3* _db;
};