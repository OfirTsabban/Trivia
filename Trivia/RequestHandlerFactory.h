#pragma once
#include "LoginManager.h"
#include "IDatabase.h" 
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"

enum loginDef { succeeded = true, failed = false };

class RoomMemberRequestHandler;
class RoomAdminRequestHandler;
class MenuRequestHandler;
class LoginRequestHandler;


class RequestHandlerFactory
{
public:
	RequestHandlerFactory(IDatabase* db);
	~RequestHandlerFactory();
	LoginRequestHandler* createLoginRequestHandler();
	LoginManager& getLoginManager();
	MenuRequestHandler* createMenuRequestHandler(LoggedUser user);
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
	RoomAdminRequestHandler* createRoomAdminRequestHandler(LoggedUser user, Room room);
	RoomMemberRequestHandler* createRoomMemberRequestHandler(LoggedUser user, Room room);
private:
	RoomManager& m_roomManager;
	IDatabase* m_database;
	LoginManager m_loginManager;
	StatisticsManager m_StatisticsManager;
};
