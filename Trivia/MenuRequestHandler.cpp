#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory& handleFactory, LoggedUser& user) : m_user(user), m_handlerFactory(handleFactory), m_roomManager(handleFactory.getRoomManager()),
 m_statisticsManager(handleFactory.getStatisticsManager())
{
}

bool MenuRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
	return reqInfo.id == Sign_Out ||
		reqInfo.id == Get_Rooms ||
		reqInfo.id == Get_Players ||
		reqInfo.id == Get_Personal_Stats ||
		reqInfo.id == Get_High_Score ||
		reqInfo.id == Join_Room ||
		reqInfo.id == Create_Room;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo reqInfo)
{
	if (reqInfo.id == Sign_Out)
	{
		return signout(reqInfo);
	}
	else if (reqInfo.id == Get_Rooms)
	{
		return getRooms(reqInfo);
	}
	else if (reqInfo.id == Get_Players)
	{
		return getPlayers(reqInfo);
	}
	else if (reqInfo.id == Get_Personal_Stats)
	{
		return getPersonalStats(reqInfo);
	}
	else if (reqInfo.id == Get_High_Score)
	{
		return getHighScore(reqInfo);
	}
	else if (reqInfo.id == Join_Room)
	{
		return joinRoom(reqInfo);
	}
	else if (reqInfo.id == Create_Room)
	{
		return createRoom(reqInfo);
	}
}

RequestResult MenuRequestHandler::signout(const RequestInfo reqInfo)
{
	RequestResult reqRes;

	LoginManager manager = m_handlerFactory.getLoginManager();
	manager.logout(m_user.getUsername());

	//need to wait for ofir to continue
}

RequestResult MenuRequestHandler::getRooms(const RequestInfo reqInfo)
{
	std::vector<RoomData> rooms = m_roomManager.getRooms();

	//need to wait for ofir to continue
}

RequestResult MenuRequestHandler::getPlayers(const RequestInfo reqInfo)
{
	GetPlayersInRoomRequest getPlayersRequest = JsonRequestPacketDeserializer::deserializeGetPlayersRequest((char*)reqInfo.buffer);

	Room currRoom = m_roomManager.getRoom(getPlayersRequest.roomId);
	std::vector<std::string> allPlayers = currRoom.getAllUsers();

	//need to wait for ofir to continue
}

RequestResult MenuRequestHandler::getPersonalStats(const RequestInfo reqInfo)
{
	std::vector<std::string> stats = m_statisticsManager.getUserStatistics(m_user.getUsername());

	//need to wait for ofir to continue
}

RequestResult MenuRequestHandler::getHighScore(const RequestInfo reqInfo)
{
	std::vector<std::string> highScore = m_statisticsManager.getHighScore();

	//need to wait for ofir to continue
}

RequestResult MenuRequestHandler::joinRoom(const RequestInfo reqInfo)
{
	JoinRoomRequest joinReq = JsonRequestPacketDeserializer::deserializeJoinRoomRequest((char*)reqInfo.buffer);
	Room currRoom = m_roomManager.getRoom(joinReq.roomId);
	currRoom.addUser(m_user);

	//need to wait for ofir to continue
}

RequestResult MenuRequestHandler::createRoom(const RequestInfo reqInfo)
{
	CreateRoomRequest createRoomReq = JsonRequestPacketDeserializer::deserializeCreateRoomRequest((char*)reqInfo.buffer);
	RoomData newRoomData = { 1, createRoomReq.roomName, createRoomReq.maxUsers, createRoomReq.questionCount, createRoomReq.answerTimeout, 1/*dont know what to put in here*/ };//will change ID to random nuber later...
	
	m_roomManager.createRoom(m_user, newRoomData);
}

