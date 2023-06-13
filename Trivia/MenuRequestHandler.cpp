#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory& handleFactory, LoggedUser& user) : m_user(user), m_handlerFactory(handleFactory), m_roomManager(handleFactory.getRoomManager()),
 m_statisticsManager(handleFactory.getStatisticsManager())
{
}

bool MenuRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
	return reqInfo.id == Log_Out ||
		reqInfo.id == Get_Rooms ||
		reqInfo.id == Get_Players ||
		reqInfo.id == Get_Personal_Stats ||
		reqInfo.id == Get_High_Score ||
		reqInfo.id == Join_Room ||
		reqInfo.id == Create_Room;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo reqInfo, SOCKET user_socket)
{
	if (reqInfo.id == Log_Out)
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
	LoginManager& manager = m_handlerFactory.getLoginManager();
	manager.logout(m_user.getUsername());

	LogoutResponse logOutResp = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(logOutResp);

	IRequestHandler* handle = m_handlerFactory.createLoginRequestHandler();

	RequestResult reqRes = { response, handle };
	return reqRes;
}

RequestResult MenuRequestHandler::getRooms(const RequestInfo reqInfo)
{
	std::vector<RoomData> rooms = m_roomManager.getRooms();

	GetRoomsResponse roomResp = { 1 , rooms };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(roomResp);

	IRequestHandler* handle = m_handlerFactory.createMenuRequestHandler(this->m_user);//change it when roomHandle is created

	RequestResult reqRes = { response, handle };
	return reqRes;
}

RequestResult MenuRequestHandler::getPlayers(const RequestInfo reqInfo)
{
	GetPlayersInRoomRequest getPlayersRequest = JsonRequestPacketDeserializer::deserializeGetPlayersRequest((char*)reqInfo.buffer);

	Room& currRoom = m_roomManager.getRoom(getPlayersRequest.roomId);
	std::vector<std::string> allPlayers = currRoom.getAllUsersNames();

	GetPlayersInRoomResponse playersInRoomResp = { allPlayers };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(playersInRoomResp);

	IRequestHandler* handle = m_handlerFactory.createMenuRequestHandler(this->m_user);//change it when roomHandle is created

	RequestResult reqRes = { response, handle };
	return reqRes;
}

RequestResult MenuRequestHandler::getPersonalStats(const RequestInfo reqInfo)
{
	std::vector<std::string> stats = m_statisticsManager.getUserStatistics(m_user.getUsername());

	GetPersonalStatsResponse personalStatsResp = { 1, stats };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(personalStatsResp);

	IRequestHandler* handle = m_handlerFactory.createMenuRequestHandler(this->m_user);//change it when roomHandle is created

	RequestResult reqRes = { response, handle };
	return reqRes;
}

RequestResult MenuRequestHandler::getHighScore(const RequestInfo reqInfo)
{
	std::vector<std::string> highScore = m_statisticsManager.getHighScore();

	GetHighScoreResponse highScoreResp = { 1, highScore };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(highScoreResp);

	IRequestHandler* handle = m_handlerFactory.createMenuRequestHandler(this->m_user);//change it when roomHandle is created

	RequestResult reqRes = { response, handle };
	return reqRes;
}

RequestResult MenuRequestHandler::joinRoom(const RequestInfo reqInfo)
{
	JoinRoomRequest joinReq = JsonRequestPacketDeserializer::deserializeJoinRoomRequest((char*)reqInfo.buffer);
	this->m_roomManager.getRoom(joinReq.roomId).addUser(m_user);
	JoinRoomResponse joinRoomResp = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(joinRoomResp);

	IRequestHandler* handle = m_handlerFactory.createRoomMemberRequestHandler(this->m_user,this->m_roomManager.getRoom(joinReq.roomId));//change it when roomHandle is created

	RequestResult reqRes = { response, handle };
	return reqRes;
}

RequestResult MenuRequestHandler::createRoom(const RequestInfo reqInfo)
{
	CreateRoomRequest createRoomReq = JsonRequestPacketDeserializer::deserializeCreateRoomRequest((char*)reqInfo.buffer);
	/*unsigned int roomID = 0;*/
	RoomData newRoomData = { 0, createRoomReq.roomName, createRoomReq.maxUsers, createRoomReq.questionCount, createRoomReq.answerTimeout, 1/*dont know what to put in here*/ };//will change ID to random nuber later...
	
	m_roomManager.createRoom(m_user, newRoomData);

	CreateRoomResponse createRoomResp = { 0 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(createRoomResp);

	IRequestHandler* handle = m_handlerFactory.createRoomAdminRequestHandler(this->m_user, this->m_roomManager.getRoom(0));//change it when roomHandle is created

	RequestResult reqRes = { response, handle };
	return reqRes;
}

//int MenuRequestHandler::createRoomID()
//{
//	int id = 0;
//	do 
//	{
//		id = 100 + (rand() % 101);//id will be between 100 - 200
//
//	} while (std::find(m_roomsID.begin(), m_roomsID.end(), id) != m_roomsID.end());
//
//	m_roomsID.push_back(id);
//	return id;
//}

