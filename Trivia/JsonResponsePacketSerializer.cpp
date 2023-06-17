#include "JsonResponsePacketSerializer.h"

using json = nlohmann::json;

unsigned char* JsonResponsePacketSerializer::serializeErrorResponse(ErrorResponse ep)
{	
	auto json = nlohmann::json::parse("message:" + ep.message); 
	unsigned char* buffer = new unsigned char(5 + json.size());
	buffer[0] = Error;
	int cut = 1000;
	int length = json.size();
	for (int i = 1; i < 5; i++)
	{
		buffer[i] = json.size() / cut;
		cut /= 10;
	}
	buffer[5] = json;
	std::cout << buffer << std::endl;
	return buffer;
}

unsigned char* JsonResponsePacketSerializer::serializeLoginResponse(LoginResponse lr)
{
	json jsonMSG = { {"status", lr.status} };
	std::string s = std::to_string(Log_In);
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeSignupResponse(SignupResponse sur)
{	
	json jsonMSG = { {"status", sur.status} };
	std::string s = std::to_string(Sign_Up);
	return help(jsonMSG, s); 
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(LogoutResponse logRep)
{
	json jsonMSG = { {"status", logRep.status} }; 
	std::string s = std::to_string(Log_Out);
	return help(jsonMSG, s);
}
unsigned char* JsonResponsePacketSerializer::serializeResponse(GetRoomsResponse getRoom)
{
	std::string rooms = "";
	for (int i = 0; i < getRoom.rooms.size(); i++)
	{
		rooms += " id: " + std::to_string(getRoom.rooms[i].id) + ", isActive: " + std::to_string(getRoom.rooms[i].isActive) + ", maxPlayers: " + std::to_string(getRoom.rooms[i].maxPlayers) + ", name: " + getRoom.rooms[i].name + ", numQuestions: " + std::to_string(getRoom.rooms[i].numOfQuestionsInGame) + ", timePerQuestion: " + std::to_string(getRoom.rooms[i].timePerQuestion) + "/";
	}
	std::cout << rooms << std::endl;
	json jsonMSG = { { "Rooms", rooms } };
	std::string s = std::to_string(Get_Rooms);
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse getPlayers)
{
	std::string players = "";
	for (int i = 0; i < getPlayers.players.size(); i++)
	{		
		players += getPlayers.players[i] + ",";  
	}
	std::cout << players << std::endl;
	json jsonMSG = { {"Players", players} };
	std::string s = std::to_string(Get_Players);
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse joinRoom)
{
	json jsonMSG = { { "status", joinRoom.status } };
	std::string s = std::to_string(Join_Room);
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse createRoom)
{
	json jsonMSG = { {"status" , createRoom.status} };//status = roomID
	std::string s = std::to_string(Create_Room);
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(GetHighScoreResponse highScore)
{
	int maxScore = std::stoi(highScore.statistics[0]);
	int score = 0;
	for (int i = 0; i < highScore.statistics.size(); i++)
	{
		score = std::stoi(highScore.statistics[i]);
		if (score > maxScore)
		{
			maxScore = score;
		}
	}
	json jsonMSG = { {"Max Score", maxScore} };
	std::string s = std::to_string(Get_High_Score);
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(GetPersonalStatsResponse personalStatus)
{
	std::string statistics = "";
	for (int i = 0; i < personalStatus.statistics.size(); i++)
	{		
		statistics += personalStatus.statistics[i] + ",";
	}
	json jsonMSG = { {"personal statistics", statistics} };
	std::string s = std::to_string(Get_Personal_Stats);
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(CloseRoomResponse closeRoom)
{
	json jsonMSG = { {"CloseRoom" , closeRoom.status} };
	std::string s = std::to_string(Close_Room); 
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(StartGameResponse startGame)
{
	json jsonMSG = { {"StartGame" , startGame.status} };
	std::string s = std::to_string(Member_Start_Game);
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse roomState)
{
	std::string rState = "status: " + std::to_string(roomState.status) + "/has game begun: " + std::to_string(roomState.hasGameBegun) + "/question count: " + std::to_string(roomState.questionCount) + "/answer time out: " + std::to_string(roomState.answerTimeout) + "/players:/";
	for (int i = 0; i < roomState.players.size(); i++)
	{
		rState += roomState.players[i] + "/"; 
	}
	std::string s = std::to_string(Room_State);
	json jsonMSG = { {"roomState", rState} };
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse leaveRoom)
{
	json jsonMSG = { {"LeaveRoom", leaveRoom.status} };
	std::string s = std::to_string(Leave_Room);
	return help(jsonMSG, s);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(GetGameResultsResponse gameResults)
{
	return nullptr;
}


unsigned char* JsonResponsePacketSerializer::help(json jsonMSG , std::string mode)
{
	std::string str_json = jsonMSG.dump();

	
	int cut = 1000;
	int length = str_json.length();
	std::string len = std::to_string(str_json.length());
	while (len.length() < 4)
	{
		len = "0" + len;
	}
	mode += len;
	for (int i = 0; i < str_json.length(); i++)
	{
		mode += str_json[i];
	}
	unsigned char* buffer = new unsigned char[(mode.length() + 1)];
	std::copy(mode.begin(), mode.end(), buffer);
	buffer[mode.length()] = 0;
	return buffer;
}
