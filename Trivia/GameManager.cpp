#include "GameManager.h"

GameManager::GameManager(IDatabase* db) :m_database(db)
{
}

Game GameManager::createGame(Room room)
{
	std::list<Question> questionsList = this->m_database->getQuestions(room.getData().numOfQuestionsInGame);
	std::vector<Question> questions;
	for (Question const& q : questionsList) {
		questions.push_back(q);
	}
	std::vector<LoggedUser> players = room.getAllUsers();
	unsigned int roomID = room.getData().id;
	this->m_games.push_back(Game(questions, players, roomID));
	return Game(questions, players, roomID);
}

void GameManager::deleteGame(unsigned int gameId)
{
	for (auto it = m_games.begin(); it != m_games.end(); it++)
	{
		if (it->getGameId() == gameId)
		{
			this->m_games.erase(it);
		}
	}

	throw("Game wasn't found");
}
