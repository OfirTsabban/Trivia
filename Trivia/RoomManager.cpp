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
	int id = 0;

	if (m_rooms.find(newRoomData.id) != m_rooms.end())
	{
		throw ExceptionHandler("Error - room already exists");
	}
	else
	{
		newRoomData.isActive = 0;

		std::unique_lock<std::mutex> lock(this->roomMutex);
		id = roomCounter;
		newRoomData.id = id;
		std::shared_ptr<Room> newRoom = std::shared_ptr<Room>(new Room(newRoomData));
		newRoom->addUser(host);
		this->m_rooms.emplace(std::make_pair(roomCounter, newRoom));

		roomCounter++;
	}

	return id;
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
		this->m_rooms.at(ID)->setStatus(3);
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

void RoomManager::setRoomState(const int ID, int state) const
{
	if (m_rooms.find(ID) == m_rooms.end())
	{
		throw ExceptionHandler("Error - room doesn't already exists");
	}
	else
	{
		this->m_rooms.find(ID)->second->setStatus(state);
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

std::shared_ptr<Room> RoomManager::getRoom(int ID)
{
	std::unique_lock<std::mutex> lock(this->roomMutex);
	for (auto&& it = m_rooms.begin(); it != m_rooms.end(); it++)
	{
		if (it->first == ID)
		{
			return it->second;
		}
	}
}
