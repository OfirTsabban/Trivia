#pragma once
#include "IRequestHandler.h"
#include "Room.h"
#include "LoggedUser.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class RoomAdminRequestHandler : public IRequestHandler
{
public:
	RoomAdminRequestHandler(Room& room, LoggedUser& user, RequestHandlerFactory& handleFactory);
	bool isRequestRelevent(RequestInfo)override;
	RequestResult handleRequest(RequestInfo, SOCKET)override;
private:
	Room m_room;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handleFactory;
	RequestResult closeRoom(RequestInfo, SOCKET);
	RequestResult startGame(RequestInfo, SOCKET);
	RequestResult getRoomState(RequestInfo); 
	RequestResult getPlayers(const RequestInfo reqInfo);
};

