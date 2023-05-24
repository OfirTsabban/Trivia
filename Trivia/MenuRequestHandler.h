#pragma once
#include "IRequestHandler.h"
#include "LoggedUser.h"
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"

class RequestHandlerFactory;

class MenuRequestHandler : public IRequestHandler
{ 
public:
	MenuRequestHandler(RequestHandlerFactory& handleFactory, LoggedUser& user);
	~MenuRequestHandler() = default;
	bool isRequestRelevent(RequestInfo reqInfo) override;
	RequestResult handleRequest(RequestInfo reqInfo) override;
private:
	RequestResult signout(const RequestInfo reqInfo);
	RequestResult getRooms(const RequestInfo reqInfo);
	RequestResult getPlayers(const RequestInfo reqInfo);
	RequestResult getPersonalStats(const RequestInfo reqInfo);
	RequestResult getHighScore(const RequestInfo reqInfo);
	RequestResult joinRoom(const RequestInfo reqInfo);
	RequestResult createRoom(const RequestInfo reqInfo);


	LoggedUser m_user;
	RoomManager& m_roomManager;
	StatisticsManager& m_statisticsManager;
	RequestHandlerFactory& m_handlerFactory;
};

