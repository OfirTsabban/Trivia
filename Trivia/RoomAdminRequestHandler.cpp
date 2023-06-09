#include "RoomAdminRequestHandler.h"


RoomAdminRequestHandler::RoomAdminRequestHandler(Room room, LoggedUser user, RequestHandlerFactory handleFactory) : m_room(room), m_user(user), m_handleFactory(handleFactory), m_roomManager(this->m_handleFactory.getRoomManager())
{
}

bool RoomAdminRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
	return reqInfo.id == Close_Room || reqInfo.id == Start_Game || reqInfo.id == Room_State;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo reqInfo)
{
	switch (reqInfo.id)
	{
	case Close_Room:
		return closeRoom(reqInfo);
	case Start_Game:
		return startGame(reqInfo);
	case Room_State:
		return getRoomState(reqInfo);
	}
}

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo reqInfo)
{
	std::vector<std::string> users = this->m_room.getAllUsers();
	for (int i = 0; i < users.size(); i++)
	{
		RoomMemberRequestHandler* memberReq = this->m_handleFactory.craeteRoomMemnberRequestHandler(users[i], this->m_room);		
		RequestInfo info = { Leave_Room, std::time(nullptr) , reqInfo.buffer };
		memberReq->handleRequest(info);
	}	
	CloseRoomResponse closeRoom = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(closeRoom);

	IRequestHandler* handler = this->m_handleFactory.craeteRoomAdminRequestHandler(this->m_user, this->m_room);
	RequestResult reqResult = { response, handler };
	return reqResult;
}

RequestResult RoomAdminRequestHandler::startGame(RequestInfo reqInfo)
{
	std::vector<std::string> users = this->m_room.getAllUsers();
	for (int i = 0; i < users.size(); i++)
	{
		RoomMemberRequestHandler* memberReq = this->m_handleFactory.craeteRoomMemnberRequestHandler(users[i], this->m_room);
		RequestInfo info = { Start_Game, std::time(nullptr) , reqInfo.buffer };
		memberReq->handleRequest(info); 
	}
	StartGameResponse startGame = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(startGame);

	IRequestHandler* handler = this->m_handleFactory.craeteRoomAdminRequestHandler(this->m_user, this->m_room);
	RequestResult reqResult = { response, handler };
	return reqResult;
}

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo reqInfo)
{	
	/*GetRoomStateResponse  roomState = { this->m_room.getData().id , reqInfo.};
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(roomState);
	
	IRequestHandler* handler = this->m_handleFactory.craeteRoomAdminRequestHandler(this->m_user, this->m_room);
	RequestResult reqResult = { response, handler };*/
}
