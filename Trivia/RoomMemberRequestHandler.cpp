#include "RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler(Room room, LoggedUser user, RequestHandlerFactory factory) : m_room(room), m_user(user), m_handleFactory(factory), m_roomManager(this->m_handleFactory.getRoomManager())
{
}

bool RoomMemberRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
	return reqInfo.id == Leave_Room || reqInfo.id == Room_State || reqInfo.id == Member_Start_Game;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo reqInfo, SOCKET user_socket)
{
	switch (reqInfo.id)
	{
	case Leave_Room:
		return leaveRoom(reqInfo);		
	case Room_State:
		return getRoomState(reqInfo, user_socket);
	case Member_Start_Game:
		return startGame(reqInfo, user_socket);
	}
}

RequestResult RoomMemberRequestHandler::leaveRoom(RequestInfo reqInfo)
{
	this->m_room.removeUser(this->m_user);
	LeaveRoomResponse leaveRoom = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(leaveRoom); 

	IRequestHandler* handler = this->m_handleFactory.createMenuRequestHandler(this->m_user);
	RequestResult reqResult = { response, handler };
	return reqResult;

}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo reqInfo, SOCKET user_socket)
{	
	return this->m_handleFactory.createRoomAdminRequestHandler(this->m_user, this->m_room)->handleRequest(reqInfo, user_socket);
}

RequestResult RoomMemberRequestHandler::startGame(RequestInfo reqInfo, SOCKET user_socket)
{
	StartGameResponse startGame = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(startGame);

	IRequestHandler* handler = this->m_handleFactory.createRoomMemberRequestHandler(this->m_user, this->m_room);
	RequestResult reqResult = { response, handler };
	return reqResult;
}
