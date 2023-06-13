#include "RoomAdminRequestHandler.h"


RoomAdminRequestHandler::RoomAdminRequestHandler(Room& room, LoggedUser& user, RequestHandlerFactory& handleFactory) : m_user(user), m_roomManager(handleFactory.getRoomManager()), m_handleFactory(handleFactory), m_room(room)
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
	case Get_Players:
		return getPlayers(reqInfo);
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
	GetRoomStateResponse  roomState = { this->m_room.getData().id, this->m_room.getData().isActive, this->m_room.getAllUsersNames(), this->m_room.getData().numOfQuestionsInGame, this->m_room.getData().timePerQuestion};
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(roomState);
	
	//IRequestHandler* handler = this->m_handleFactory.createRoomAdminRequestHandler(this->m_user, this->m_room);
	RequestResult reqResult = { response, this };
	return reqResult;
}

RequestResult RoomAdminRequestHandler::getPlayers(const RequestInfo reqInfo)
{
	std::vector<std::string> allPlayers = m_roomManager.getRoom(this->m_room.getData().id).getAllUsersNames();

	GetPlayersInRoomResponse playersInRoomResp = { allPlayers };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(playersInRoomResp);

	IRequestHandler* handle = this;

	RequestResult reqRes = { response, handle };
	return reqRes;
}
