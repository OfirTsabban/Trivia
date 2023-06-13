#include "RoomManager.h"

RoomManager::RoomManager()
{
	roomCounter = 0;
}


RoomManager::~RoomManager()
{
	m_rooms.clear();
}

uint32_t RoomManager::createRoom(const LoggedUser host, RoomData newRoomData)
{
	if (m_rooms.find(newRoomData.id) != m_rooms.end())
	{
		throw ExceptionHandler("Error - room already exists");
	}
	else
	{
		newRoomData.isActive = 1;//when room is created it's automaticly activates

		std::unique_lock<std::mutex> lock(this->roomMutex);
		newRoomData.id = roomCounter;
		Room* newRoom = new Room(newRoomData);
		newRoom->addUser(host);
		this->m_rooms.emplace(std::make_pair(roomCounter, newRoom));

		roomCounter++;
	}
}

void RoomManager::deleteRoom(int ID)
{
	std::unique_lock<std::mutex> lock(this->roomMutex);
	if (m_rooms.find(ID) == m_rooms.end())
	{
		
		throw ExceptionHandler("Error - room doesn't already exists");
	}
	else
	{
		delete this->m_rooms.at(ID);
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
		return this->m_rooms.find(ID)->second->getData().isActive;
	}
}

std::vector<RoomData> RoomManager::getRooms()
{
	std::vector<RoomData> rooms;

	std::unique_lock<std::mutex> lock(this->roomMutex);
	for (auto iter = this->m_rooms.begin(); iter != this->m_rooms.end(); iter++)
	{
		rooms.push_back(iter->second->getData());
	}

	return rooms;
}

Room& RoomManager::getRoom(int ID)
{
	std::map<unsigned int, Room*>::iterator it;

	std::unique_lock<std::mutex> lock(this->roomMutex);
	for (it = m_rooms.begin(); it != m_rooms.end(); it++)
	{
		if (it->first == ID)
		{
			return *it->second;
		}
	}
}
