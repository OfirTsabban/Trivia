#pragma once
#include <iostream>
#include "json.hpp"
#include <string>

#include "Communicator.h"
struct LoginResponse
{
	unsigned int status;
};
struct SignupResponse
{
	unsigned int status;
};
struct ErrorResponse
{
	std::string message;
};
struct LogoutResponse
{
	unsigned int status;
};
struct GetRoomsResponse
{
	unsigned int status;
	vector<RoomData> rooms;
};
struct GetPlayersInRoomResponse
{
	vector<std::string> players;
};
struct GetHighScoreResponse
{
	unsigned int status;
	vector<std::string> statistics;
};
struct GetPersonalStatsResponse
{
	unsigned int status;
	vector<std::string> statistics;
};
struct JoinRoomResponse
{
	unsigned int status;
};
struct CreateRoomResponse
{
	unsigned int status;
};

enum Requests {
	Error = 0,
	Log_In = 1,
	Sign_Up = 2,
	Sign_Out = 3,
	Get_Rooms = 4,
	Get_Players = 5,
	Get_Personal_Stats = 6,
	Get_High_Score = 7,
	Join_Room = 8,
	Create_Room = 9,
};
class JsonResponsePacketSerializer
{
public:
	static unsigned char* serializeErrorResponse(ErrorResponse); 
	static unsigned char* serializeLoginResponse(LoginResponse);
	static unsigned char* serializeSignupResponse(SignupResponse); 
	static unsigned char* serializeResponse(LogoutResponse);
	static unsigned char* serializeResponse(GetRoomsResponse);
	static unsigned char* serializeResponse(GetPlayersInRoomResponse);
	static unsigned char* serializeResponse(JoinRoomResponse);
	static unsigned char* serializeResponse(CreateRoomResponse);
	static unsigned char* serializeResponse(GetHighScoreResponse);
	static unsigned char* serializeResponse(GetPersonalStatsResponse);
	static unsigned char* help(json jsonMSG);
};

