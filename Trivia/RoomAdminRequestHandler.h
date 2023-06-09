#pragma once
#include "IRequestHandler.h"
#include "Room.h"
#include "LoggedUser.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"
#include "RoomMemberRequestHandler.h"
class RequestHandlerFactory;

class RoomAdminRequestHandler : public IRequestHandler
{
public:
	RoomAdminRequestHandler(Room, LoggedUser, RequestHandlerFactory);
	bool isRequestRelevent(RequestInfo)override;
	RequestResult handleRequest(RequestInfo)override;
private:
	Room m_room;
	LoggedUser m_user;
	RoomManager& m_roomManager;
	RequestHandlerFactory& m_handleFactory;
	RequestResult closeRoom(RequestInfo);
	RequestResult startGame(RequestInfo);
	RequestResult getRoomState(RequestInfo); 
};

