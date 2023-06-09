#include "RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler(Room room, LoggedUser user, RequestHandlerFactory factory) : m_room(room), m_user(user), m_handleFactory(factory), m_roomManager(this->m_handleFactory.getRoomManager())
{
}

bool RoomMemberRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
	return reqInfo.id == Leave_Room || reqInfo.id == Room_State;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo reqInfo) 
{
	switch (reqInfo.id)
	{
	case Leave_Room:
		return leaveRoom(reqInfo);		
	case Room_State:
		return getRoomState(reqInfo);
	}
}
