#pragma once
#include <iostream>
#include <vector>
#include "ExceptionHandler.h"
#include "SqliteDatabase.h"

class StatisticsManager
{
public:
	StatisticsManager();
	~StatisticsManager() = default;
	std::vector<std::string> getHighScore() const;
	std::vector<std::string> getUserStatistics(const std::string username);

private:
	IDatabase* m_database;
};