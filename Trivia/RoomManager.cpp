#include "RoomManager.h"

RoomManager::RoomManager()
{
}


RoomManager::~RoomManager()
{
	m_rooms.clear();
}

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
		this->roomMutex.lock();
		newRoom.addUser(host);
		this->m_rooms.insert(std::pair<int, Room>(newRoomData.id, newRoom));
		this->roomMutex.unlock();
	}
}

void RoomManager::deleteRoom(int ID)
{
	this->roomMutex.lock();
	if (m_rooms.find(ID) == m_rooms.end())
	{
		this->roomMutex.unlock();
		throw ExceptionHandler("Error - room doesn't already exists");
	}
	else
	{
		this->m_rooms.erase(ID);
		this->roomMutex.unlock();
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
	this->roomMutex.lock();
	for (auto iter = this->m_rooms.begin(); iter != this->m_rooms.end(); iter++)
	{
		rooms.push_back(iter->second.getData());
	}
	this->roomMutex.unlock();

	return rooms;
}

Room& RoomManager::getRoom(int ID)
{
	std::map<int, Room>::iterator it;
	this->roomMutex.lock();
	for (it = m_rooms.begin(); it != m_rooms.end(); it++)
	{
		if (it->first == ID)
		{
			this->roomMutex.unlock();
			return it->second;
		}
	}
	this->roomMutex.unlock();

}
