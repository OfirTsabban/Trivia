#pragma once
#include "LoginManager.h"
#include "GameRequestHandler.h"
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"

enum loginDef { succeeded = true, failed = false };

class LoginRequestHandler;
class MenuRequestHandler;
class RoomAdminRequestHandler;
class RoomMemberRequestHandler;
class GameRequestHandler;
class GameManager;

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
	RoomAdminRequestHandler* createRoomAdminRequestHandler(LoggedUser user, std::shared_ptr<Room> room);
	RoomMemberRequestHandler* createRoomMemberRequestHandler(LoggedUser user, std::shared_ptr<Room> room);
	GameRequestHandler* createGameRequestHandler(LoggedUser user, Game game);
	GameManager& getGameManager();
	
private:
	IDatabase* m_database;
	LoginManager m_loginManager;
	RoomManager m_roomManager;
	StatisticsManager m_StatisticsManager;
};
