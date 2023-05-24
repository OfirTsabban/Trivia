#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory& handleFactory, LoggedUser& user) : m_user(user), m_handlerFactory(handleFactory), m_roomManager(handleFactory.getRoomManager()),
 m_statisticsManager(handleFactory.getStatisticsManager())
{
}

bool MenuRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
	
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo reqInfo)
{
	return RequestResult();
}

