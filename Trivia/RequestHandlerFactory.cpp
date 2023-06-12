#include "RequestHandlerFactory.h"
#include "LoginRequestHandler.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* db) : m_database(db), m_loginManager(db), m_roomManager(this->m_roomManager), m_StatisticsManager()
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

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(LoggedUser user)
{
	MenuRequestHandler* menu = new MenuRequestHandler(*this, user);
	return menu;
}

StatisticsManager& RequestHandlerFactory::getStatisticsManager() 
{
	return this->m_StatisticsManager;
}

RoomManager& RequestHandlerFactory::getRoomManager()
{
	return this->m_roomManager;
}

RoomAdminRequestHandler* RequestHandlerFactory::createRoomAdminRequestHandler(LoggedUser user, Room room)
{
	RoomAdminRequestHandler* roomAdmin = new RoomAdminRequestHandler(room, user, *this);
	return roomAdmin;
}

RoomMemberRequestHandler* RequestHandlerFactory::createRoomMemberRequestHandler(LoggedUser user, Room room)
{
	RoomMemberRequestHandler* roomMember = new RoomMemberRequestHandler(room, user, *this);
	return roomMember;
}
