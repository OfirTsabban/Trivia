#include "RequestHandlerFactory.h"

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	LoginRequestHandler* login = new LoginRequestHandler(...);
	return login;
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return this->getLoginManager();
}
