#pragma once
#include <vector>
#include <iostream>
#include <mutex>
#include "LoggedUser.h"
#include "ExceptionHandler.h"

using std::mutex;

typedef struct RoomData
{
	unsigned int id;
	std::string name;
	unsigned int maxPlayers;
	unsigned int numOfQuestionsInGame;
	unsigned int timePerQuestion;
	unsigned int isActive;
} RoomData;

class Room
{
public:
	Room(RoomData metadata);
	void addUser(const LoggedUser user);
	void removeUser(const LoggedUser user);
	std::vector<std::string> getAllUsersNames();
	std::vector<LoggedUser> getAllUsers();
	RoomData getData() const;
	void setStatus(int status);

private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;
	mutex roomMutex;
};