#include "RequestHandlerFactory.h"

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	switch (/*i need to add an if*/)
	{
	case succeeded:
		//IRequestHandler* menu = new MenuRequestHandler();
		//return menu;
	case failed:
		LoginRequestHandler* login = new LoginRequestHandler();
		return login;
	default:
		break;
	}
}
