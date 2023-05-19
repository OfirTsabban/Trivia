#include "Room.h"

Room::Room(RoomData metadata)
{
	this->m_metadata = metadata;
}

void Room::addUser(LoggedUser user)
{
	if (this->m_users.size() == this->m_metadata.maxPlayers)
	{
		throw ExceptionHandler("Error - Room is full");
	}
	else if (std::find(m_users.begin(), m_users.end(), user) != m_users.end())
	{
		throw ExceptionHandler("Error - User is already playing in this room");
	}
	else
	{
		this->m_users.push_back(user);
	}
}

void Room::removeUser(LoggedUser user)
{
	for (auto iter = this->m_users.begin(); iter != this->m_users.end(); iter++)
	{
		if (*iter == user)
		{
			this->m_users.erase(iter);
			return;
		}
	}

	throw ExceptionHandler("Error - User doesn't exist in room");
}

std::vector<std::string> Room::getAllUsers()
{
	std::vector<std::string> allUsers;
	for (auto iter = this->m_users.begin(); iter != this->m_users.end(); iter++)
	{
		allUsers.push_back(iter->getUsername());
	}

	return allUsers;
}

