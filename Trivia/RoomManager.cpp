#include "RoomManager.h"

void RoomManager::createRoom(const LoggedUser host, RoomData newRoomData)
{
	if (m_rooms.find(newRoomData.id) != m_rooms.end())
	{
		throw ExceptionHandler("Error - room already exists");
	}
	else
	{
		newRoomData.isActive = 1;//when room is created it's automaticly activates
		Room newRoom(newRoomData);
		this->m_rooms.insert(std::pair<int, Room>(newRoomData.id, newRoom));
	}
}

void RoomManager::deleteRoom(int ID)
{
	if (m_rooms.find(ID) == m_rooms.end())
	{
		throw ExceptionHandler("Error - room doesn't already exists");
	}
	else
	{
		this->m_rooms.erase(ID);
	}
}

unsigned int RoomManager::getRoomState(const int ID) const
{
	if (m_rooms.find(ID) == m_rooms.end())
	{
		throw ExceptionHandler("Error - room doesn't already exists");
	}
	else
	{
		return this->m_rooms.find(ID)->second.getData().isActive;
	}
}

std::vector<RoomData> RoomManager::getRooms()
{
	std::vector<RoomData> rooms;
	for (auto iter = this->m_rooms.begin(); iter != this->m_rooms.end(); iter++)
	{
		rooms.push_back(iter->second.getData());
	}

	return rooms;
}

Room& RoomManager::getRoom(int ID)
{
	return m_rooms.at(ID);
}