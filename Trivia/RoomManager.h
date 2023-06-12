#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "ExceptionHandler.h"
#include "LoggedUser.h"
#include "Room.h"


class RoomManager
{
public:
	RoomManager();
	~RoomManager();
	void createRoom(const LoggedUser host, RoomData newRoomData);
	void deleteRoom(const int ID);
	unsigned int getRoomState(const int ID) const;
	std::vector<RoomData> getRooms();
	Room& getRoom(int ID);

private:
	std::map<int, Room> m_rooms;
};