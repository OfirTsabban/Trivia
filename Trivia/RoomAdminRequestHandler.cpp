#include "RoomAdminRequestHandler.h"


RoomAdminRequestHandler::RoomAdminRequestHandler(Room room, LoggedUser user, RequestHandlerFactory handleFactory) : m_room(room), m_user(user), m_handleFactory(handleFactory), m_roomManager(this->m_handleFactory.getRoomManager())
{
}

bool RoomAdminRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
	return reqInfo.id == Close_Room || reqInfo.id == Admin_Start_Game || reqInfo.id == Room_State;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo reqInfo, SOCKET user_socket)
{
	switch (reqInfo.id)
	{
	case Close_Room:
		return closeRoom(reqInfo, user_socket);
	case Admin_Start_Game:
		return startGame(reqInfo, user_socket);
	case Room_State:
		return getRoomState(reqInfo);
	}
}

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo reqInfo, SOCKET userSocket)
{
	std::vector<LoggedUser> users = this->m_room.getAllUsers();
	for (int i = 0; i < users.size(); i++)
	{
		IRequestHandler* memberReq = this->m_handleFactory.createRoomMemberRequestHandler(users[i], this->m_room);		
		RequestInfo info = { Leave_Room, std::time(nullptr) , reqInfo.buffer };
		RequestResult reqRes = memberReq->handleRequest(info, users[i].getUserSocket());
		Helper::sendData(users[i].getUserSocket(), reinterpret_cast<char*>(reqRes.response));
	}	
	this->m_room.removeUser(this->m_user);
	CloseRoomResponse closeRoom = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(closeRoom);

	IRequestHandler* handler = this->m_handleFactory.createMenuRequestHandler(this->m_user);
	RequestResult reqResult = { response, handler };
	return reqResult;
}

RequestResult RoomAdminRequestHandler::startGame(RequestInfo reqInfo, SOCKET userSocket)
{
	StartGameResponse startGame = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(startGame);
	std::vector<LoggedUser> users = this->m_room.getAllUsers();
	for (int i = 0; i < users.size(); i++)
	{
		IRequestHandler* memberReq = this->m_handleFactory.createRoomMemberRequestHandler(users[i], this->m_room);
		RequestInfo info = { Member_Start_Game, std::time(nullptr) , reqInfo.buffer };
		RequestResult reqRes = memberReq->handleRequest(info, users[i].getUserSocket());
		Helper::sendData(users[i].getUserSocket(), reinterpret_cast<char*>(reqRes.response));
	}
	

	IRequestHandler* handler = nullptr;//need game handler
	RequestResult reqResult = { response, handler };
	return reqResult;
}

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo reqInfo)
{			
	std::vector<std::string> allPlayers;
	std::vector<LoggedUser> users;
	for (auto& user : this->m_room.getAllUsers())
	{
		allPlayers.push_back(user.getUsername());
	}
	GetRoomStateResponse  roomState = { this->m_room.getData().id, this->m_room.getData().isActive, allPlayers, this->m_room.getData().numOfQuestionsInGame, this->m_room.getData().timePerQuestion};
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(roomState);
	
	//IRequestHandler* handler = this->m_handleFactory.createRoomAdminRequestHandler(this->m_user, this->m_room);
	RequestResult reqResult = { response, this };
	return reqResult;
}
