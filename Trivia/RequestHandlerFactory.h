#pragma once
#include "LoginManager.h"
#include "IDatabase.h" 
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "GameManager.h"

enum loginDef { succeeded = true, failed = false };

class GameManager;
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
	GameManager& getGameManager();
	
private:
	IDatabase* m_database;
	LoginManager m_loginManager;
	RoomManager m_roomManager;
	StatisticsManager m_StatisticsManager;
	GameManager m_gameManager;
};
