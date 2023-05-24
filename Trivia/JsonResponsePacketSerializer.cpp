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
	return help(jsonMSG);
}

unsigned char* JsonResponsePacketSerializer::serializeSignupResponse(SignupResponse sur)
{	
	json jsonMSG = { {"status", sur.status} };
	return help(jsonMSG); 
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(LogoutResponse logRep)
{
	json jsonMSG = { {"status", logRep.status} }; 
	return help(jsonMSG);
}
unsigned char* JsonResponsePacketSerializer::serializeResponse(GetRoomsResponse getRoom)
{
	std::string rooms = "";
	for (int i = 0; i < getRoom.rooms.size(); i++)
	{
		rooms += std::to_string(getRoom.rooms[i].id) + std::to_string(getRoom.rooms[i].isActive) + std::to_string(getRoom.rooms[i].maxPlayers) + getRoom.rooms[i].name + std::to_string(getRoom.rooms[i].numOfQuestionsInGame) + std::to_string(getRoom.rooms[i].timePerQuestion);
	}
	json jsonMSG = { {"Rooms", rooms} };
	return help(jsonMSG);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse getPlayers)
{
	std::string players = "";
	for (int i = 0; i < getPlayers.players.size(); i++)
	{		
		players += getPlayers.players[i];
	}
	json jsonMSG = { {"Players", players} };
	return help(jsonMSG);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse joinRoom)
{
	json jsonMSG = { {"Players", joinRoom.status} };
	return help(jsonMSG);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse createRoom)
{
	json jsonMSG = { {"status" , createRoom.status} };
	return help(jsonMSG);
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
	return help(jsonMSG);
}

unsigned char* JsonResponsePacketSerializer::serializeResponse(GetPersonalStatsResponse personalStatus)
{
	std::string statistics = "";
	for (int i = 0; i < personalStatus.statistics.size(); i++)
	{		
		statistics += personalStatus.statistics[i];
	}
	json jsonMSG = { {"'personal statistics'", statistics} };
	return help(jsonMSG);
}


unsigned char* JsonResponsePacketSerializer::help(json jsonMSG)
{
	std::string str_json = jsonMSG.dump();

	std::string s = std::to_string(Sign_Up);
	int cut = 1000;
	int length = str_json.length();
	std::string len = std::to_string(str_json.length());
	while (len.length() < 4)
	{
		len = "0" + len;
	}
	s += len;
	for (int i = 0; i < str_json.length(); i++)
	{
		s += str_json[i];
	}
	unsigned char* buffer = new unsigned char[(s.length() + 1)];
	std::copy(s.begin(), s.end(), buffer);
	buffer[s.length()] = 0;
	std::cout << std::endl << buffer << std::endl;
	return buffer;
}
