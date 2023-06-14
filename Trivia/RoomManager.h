#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <mutex>
#include "ExceptionHandler.h"
#include "LoggedUser.h"
#include "Room.h"

using std::mutex;

class RoomManager
{
public:
	RoomManager();
	~RoomManager();
	uint32_t createRoom(const LoggedUser host, RoomData newRoomData);
	void deleteRoom(const int ID);
	unsigned int getRoomState(const int ID) const;
	void setRoomState(const int ID, int state) const;
	std::vector<RoomData> getRooms();
	Room& getRoom(int ID);

private:
	std::map<unsigned int, Room*> m_rooms;
	mutex roomMutex;
	uint32_t roomCounter;
};