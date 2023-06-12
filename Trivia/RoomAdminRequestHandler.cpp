#include "RoomAdminRequestHandler.h"


RoomAdminRequestHandler::RoomAdminRequestHandler(Room room, LoggedUser user, RequestHandlerFactory handleFactory) : m_room(room), m_user(user), m_handleFactory(handleFactory), m_roomManager(this->m_handleFactory.getRoomManager())
{
}

bool RoomAdminRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
	return reqInfo.id == Close_Room || reqInfo.id == Admin_Start_Game || reqInfo.id == Room_State;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo reqInfo)
{
	switch (reqInfo.id)
	{
	case Close_Room:
		return closeRoom(reqInfo);
	case Admin_Start_Game:
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
		IRequestHandler* memberReq = this->m_handleFactory.createRoomMemberRequestHandler(users[i], this->m_room);		
		RequestInfo info = { Leave_Room, std::time(nullptr) , reqInfo.buffer };
		memberReq->handleRequest(info); 
	}	
	this->m_room.removeUser(this->m_user);
	CloseRoomResponse closeRoom = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(closeRoom);

	IRequestHandler* handler = this->m_handleFactory.createMenuRequestHandler(this->m_user);
	RequestResult reqResult = { response, handler };
	return reqResult;
}

RequestResult RoomAdminRequestHandler::startGame(RequestInfo reqInfo)
{
	StartGameResponse startGame = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(startGame);
	std::vector<std::string> users = this->m_room.getAllUsers();
	for (int i = 0; i < users.size(); i++)
	{
		IRequestHandler* memberReq = this->m_handleFactory.createRoomMemberRequestHandler(users[i], this->m_room);
		RequestInfo info = { Member_Start_Game, std::time(nullptr) , reqInfo.buffer };
		memberReq->handleRequest(info); 
	}
	

	IRequestHandler* handler = this->m_handleFactory.createRoomAdminRequestHandler(this->m_user, this->m_room);
	RequestResult reqResult = { response, handler };
	return reqResult;
}

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo reqInfo)
{			
	GetRoomStateResponse  roomState = { this->m_room.getData().id, this->m_room.getData().isActive, this->m_room.getAllUsers(), this->m_room.getData().numOfQuestionsInGame, this->m_room.getData().timePerQuestion};
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(roomState);
	
	IRequestHandler* handler = this->m_handleFactory.createRoomAdminRequestHandler(this->m_user, this->m_room);
	RequestResult reqResult = { response, handler };
	return reqResult;
}
