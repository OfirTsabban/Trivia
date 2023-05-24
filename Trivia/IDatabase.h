#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "sqlite3.h"
#include "Question.h"

class IDatabase
{
public:
	virtual bool doesUserExist(std::string name) = 0;
	virtual bool doesPasswordMatch(std::string name, std::string password) = 0;
	virtual void addNewUser(std::string name, std::string password, std::string email, std::string street, std::string apt, std::string city, std::string prefix, std::string number, std::string yearBorn) = 0;
	virtual std::list<Question> getQuestions(int num) = 0;
	virtual float getPlayerAverageAnswerTime(std::string name) = 0;
	virtual int getNumOfCorrectAnswers(std::string name) = 0;
	virtual int getNumOfTotalAnswers(std::string name) = 0;
	virtual int getNumOfPlayerGames(std::string name) = 0;
	virtual int getPlayerScore(std::string name) = 0;
	virtual std::vector<std::string> getHighScores() = 0;
};