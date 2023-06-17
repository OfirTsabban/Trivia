#pragma once
#include <vector>
#include <map>
#include "Question.h"
#include "LoggedUser.h"

typedef struct GameData
{
	Question currentQuestion;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	float averageAnswerTime;
}GameData;

class Game
{
public:
	Question getQuestionForUser(LoggedUser);
	void submitAnswer(LoggedUser, unsigned int id);
	void removePlayer(LoggedUser);

private:
	std::vector<Question> m_questions;
	std::map<LoggedUser, GameData> m_players;
	unsigned int m_gameId;
};