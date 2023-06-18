#include "GameManager.h"
#include "JsonResponsePacketSerializer.h"

GameManager::GameManager(IDatabase* db) :m_database(db)
{
}

Game GameManager::createGame(std::shared_ptr<Room> room)
{
	std::list<Question> questionsList = this->m_database->getQuestions(room->getData().numOfQuestionsInGame);
	std::vector<Question> questions;
	std::unique_lock<std::mutex> lock(this->gameMutex);
	for (Question const& q : questionsList) {
		questions.push_back(q);
	}
	std::vector<LoggedUser> players = room->getAllUsers();
	unsigned int roomID = room->getData().id;
	this->m_games.push_back(Game(questions, players, roomID));
	Game game(questions, players, roomID);
	return game;
}

void GameManager::deleteGame(unsigned int gameId)
{
	std::unique_lock<std::mutex> lock(this->gameMutex);
	for (auto it = m_games.begin(); it != m_games.end(); it++)
	{
		if (it->getGameId() == gameId)
		{
			this->m_games.erase(it);
		}
	}

	throw("Game wasn't found");
}

Game& GameManager::getGame(int id)
{
	std::unique_lock<std::mutex> lock(this->gameMutex);
	for (Game game : this->m_games)
	{
		if (game.getGameId() == id)
		{
			return game;
		}
	}
}

std::vector<PlayerResults> GameManager::getPlayersResults(Game game)
{
	std::vector<PlayerResults> results;
	std::map<LoggedUser, GameData> currGameResults = game.getGameResults();

	for (auto&& it = currGameResults.begin(); it != currGameResults.end(); it++)
	{
		LoggedUser currUser = it->first;
		PlayerResults playerResults = { currUser.getUsername(), it->second.correctAnswerCount, it->second.wrongAnswerCount, it->second.averageAnswerTime };
		results.push_back(playerResults);
	}

	return results;
}
