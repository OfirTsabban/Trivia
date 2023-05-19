#include "RequestHandlerFactory.h"
#include "LoginRequestHandler.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* db) : m_database(db), m_loginManager(db), m_roomManager(), m_StatisticsManager()
{
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	LoginRequestHandler* login = new LoginRequestHandler(*this);
	return login;
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return this->m_loginManager;
}
