#pragma once
#include <vector>
#include <mutex>
#include "SqliteDatabase.h"
#include "Game.h"
#include "Room.h"
#include "JsonResponsePacketSerializer.h"

using std::mutex;

struct PlayerResults;

class GameManager
{
public:
	static GameManager& getInstance(IDatabase* db)
	{
		static GameManager instance(db);
		return instance;
	}
	GameManager(GameManager const&) = delete;
	void operator=(GameManager const&) = delete;
	GameManager(IDatabase* db);

	Game createGame(std::shared_ptr<Room>);
	void deleteGame(unsigned int gameId);
	Game& getGame(int id);
	std::vector<PlayerResults> getPlayersResults(Game);

private:

	IDatabase* m_database;
	std::vector<Game> m_games;
	mutex gameMutex;
};