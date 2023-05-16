#pragma once 
#include "LoginManager.h"
#include "IDatabase.h" 
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
enum loginDef { succeeded = true, failed = false }; 
class RequestHandlerFactory
{
public:
	LoginRequestHandler* createLoginRequestHandler(); 
	LoginManager& getLoginManager();
private: 
	LoginManager m_loginManager;
	IDatabase* m_database; 
};

