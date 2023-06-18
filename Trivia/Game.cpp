#include "Game.h"

Game::Game(std::vector<Question> questions, std::vector<LoggedUser> players, unsigned int gameId)
{
	std::unique_lock<std::mutex> lock(this->gameMutex);
	for (auto& question : questions)
	{
		this->m_questions.push_back(question);
	}
	for (LoggedUser user : players)
	{
		GameData gameData = { questions[0], 0, 0, 0 };
		this->m_players.emplace(std::make_pair(user, gameData));
	}

	this->m_gameId = gameId;
}

Game::Game(const Game& game)
{
	this->m_gameId = game.m_gameId;
	this->m_players = game.m_players;
	this->m_questions = game.m_questions;
}

void Game::operator=(const Game& game)
{
	*this = Game(game);
}

Question Game::getQuestionForUser(LoggedUser user)
{
	std::unique_lock<std::mutex> lock(this->gameMutex);

	for (auto it = this->m_players.begin(); it != this->m_players.end(); it++)
	{
		LoggedUser currUser = it->first;
		if (currUser == user)
		{
			return it->second.currentQuestion;
		}
	}

	throw("User wasn't found");
}

void Game::submitAnswer(LoggedUser user, unsigned int answer)
{
	auto it = m_players.find(user);
	
	if (it->second.currentQuestion.getRightAnswer() == answer)
	{
		it->second.correctAnswerCount++;
	}
	else
	{
		it->second.wrongAnswerCount++;
	}
}

void Game::removePlayer(LoggedUser user)
{
	auto it = m_players.find(user);
	m_players.erase(it);
}

unsigned int Game::getGameId()
{
	return this->m_gameId;
}

std::map<LoggedUser, GameData>& Game::getGameResults()
{
	return m_players;
}
