#include "RequestHandlerFactory.h"

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	//bool logged = this->m_database->doesUserExist(/*how to get name?*/"");
	LoginRequestHandler* login = new LoginRequestHandler();
	return login;
	//switch (logged)
	//{
	//case succeeded:
	//	IRequestHandler* menu = new MenuRequestHandler();
	//	return (LoginRequestHandler*)menu; //not sure if thats the correct way;
	//case failed:
	//	
	//default:
	//	break;
	//}
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return this->getLoginManager();
}
