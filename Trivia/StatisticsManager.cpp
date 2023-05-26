#include "StatisticsManager.h"

StatisticsManager::StatisticsManager() : m_database()
{
}

std::vector<std::string> StatisticsManager::getHighScore() const
{
	return m_database->getHighScores();
}

std::vector<std::string> StatisticsManager::getUserStatistics(const std::string username)
{
	std::vector<std::string> userStats;
	userStats.push_back(std::to_string(m_database->getPlayerAverageAnswerTime(username)));
	userStats.push_back(std::to_string(m_database->getNumOfCorrectAnswers(username)));
	userStats.push_back(std::to_string(m_database->getNumOfTotalAnswers(username)));
	userStats.push_back(std::to_string(m_database->getNumOfPlayerGames(username)));

	return userStats;
}


