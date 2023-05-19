#pragma once
#include <vector>
#include <iostream>
#include "LoggedUser.h"
#include "ExceptionHandler.h"

typedef struct RoomData
{
	unsigned int id;
	std::string name;
	unsigned int maxPlayers;
	unsigned int numOfQuestionsInGame;
	unsigned int timePerQuestion;
	unsigned int isActive;
}RoomData;

class Room
{
public:
	Room(RoomData metadata);
	void addUser(LoggedUser user);
	void removeUser(LoggedUser user);
	std::vector<std::string> getAllUsers();

private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;
};