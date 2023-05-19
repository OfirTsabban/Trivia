#pragma once
#include "LoginManager.h"
#include "IDatabase.h" 
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "MenuRequestHandler.h"


enum loginDef { succeeded = true, failed = false }; 

class LoginRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(IDatabase* db);
	~RequestHandlerFactory() = default;
	LoginRequestHandler* createLoginRequestHandler(); 
	LoginManager& getLoginManager();
	MenuRequestHandler* createMenuRequestHandler(const LoggedUser user);
	StatisticsManager& getStatisticsManager() const;
	RoomManager& getRoomManager() const;
private: 
	IDatabase* m_database;
	LoginManager m_loginManager;
	RoomManager m_roomManager;
	StatisticsManager m_StatisticsManager;
};