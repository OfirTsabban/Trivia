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
	RoomMemberRequestHandler(std::shared_ptr<Room>, LoggedUser&, RequestHandlerFactory&);
	bool isRequestRelevent(RequestInfo) override;
	RequestResult handleRequest(RequestInfo, SOCKET) override;
private:	
	RequestHandlerFactory& m_handleFactory;
	RoomManager& m_roomManager;
	std::shared_ptr<Room> m_room;
	LoggedUser m_user;
	RequestResult leaveRoom(RequestInfo);
	RequestResult getRoomState(RequestInfo, SOCKET);
	RequestResult startGame(RequestInfo, SOCKET);
	RequestResult getPlayers(const RequestInfo reqInfo);
};