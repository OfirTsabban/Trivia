#pragma once
#include "IRequestHandler.h"
#include "Room.h"
#include "LoggedUser.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class RoomMemberRequestHandler: public IRequestHandler
{
public:
	RoomMemberRequestHandler(Room, LoggedUser, RequestHandlerFactory);
	bool isRequestRelevent(RequestInfo) override;
	RequestResult handleRequest(RequestInfo) override;
private:	
	Room m_room;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handleFactory;
	RequestResult leaveRoom(RequestInfo);
	RequestResult getRoomState(RequestInfo);
	RequestResult startGame(RequestInfo);
};

