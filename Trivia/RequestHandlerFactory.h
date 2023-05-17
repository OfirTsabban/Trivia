#pragma once 
#include "LoginManager.h"
#include "IDatabase.h" 

enum loginDef { succeeded = true, failed = false }; 

class LoginRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(IDatabase* db);
	~RequestHandlerFactory() = default;
	LoginRequestHandler* createLoginRequestHandler(); 
	LoginManager& getLoginManager();
private: 
	LoginManager m_loginManager;
	IDatabase* m_database; 
};