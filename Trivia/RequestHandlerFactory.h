#pragma once
#include "LoginManager.h"
#include "IDatabase.h" 
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "GameManager.h"
#include "GameRequestHandler.h"

enum loginDef { succeeded = true, failed = false };

class GameRequestHandler;
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
	RoomAdminRequestHandler* createRoomAdminRequestHandler(LoggedUser user, std::shared_ptr<Room> room);
	RoomMemberRequestHandler* createRoomMemberRequestHandler(LoggedUser user, std::shared_ptr<Room> room);
	GameRequestHandler* createGameRequestHandler(LoggedUser user, Game game);
	GameManager& getGameManager();
	
private:
	IDatabase* m_database;
	LoginManager m_loginManager;
	RoomManager m_roomManager;
	StatisticsManager m_StatisticsManager;
	GameManager m_gameManager;
};
