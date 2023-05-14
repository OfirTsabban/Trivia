#pragma once 
#include "LoginManager.h"
#include "IDatabase.h" 
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
enum loginDef { succeeded = 1, failed = 2 };
class RequestHandlerFactory
{
public:
	LoginRequestHandler* createLoginRequestHandler(); 
	LoginManager& getLoginManager();
private: 
	LoginManager m_loginManager;
	IDatabase* m_database; 
};

