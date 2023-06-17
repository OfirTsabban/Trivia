#pragma once
#include <vector>
#include <map>
#include <mutex>
#include "Question.h"
#include "LoggedUser.h"

using std::mutex;

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
	Game(std::vector<Question> questions, std::vector<LoggedUser> players, unsigned int gameId);
	Question getQuestionForUser(LoggedUser);
	void submitAnswer(LoggedUser, std::string answer);
	void removePlayer(LoggedUser);

private:
	std::vector<Question> m_questions;
	std::map<LoggedUser, GameData> m_players;
	unsigned int m_gameId;
	mutex gameMutex;
};