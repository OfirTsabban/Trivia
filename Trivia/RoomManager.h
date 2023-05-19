#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "ExceptionHandler.h"
#include "LoggedUser.h"
#include "Room.h"

typedef struct roomID
{
	int id;
}roomID;

class RoomManager
{
public:
	void createRoom(LoggedUser host, Room newRoom);
	void deleteRoom(int ID);
	unsigned int getRoomState(int ID);
	std::vector<RoomData> getRooms();
	Room& getRooms(int ID);

private:
	std::map<roomID, Room> m_rooms;
};