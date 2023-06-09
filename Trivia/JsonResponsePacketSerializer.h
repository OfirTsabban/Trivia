#pragma once
#include <iostream>
#include "json.hpp"
#include <string>
#include <vector>
#include "Communicator.h"
#include "Room.h"

using json = nlohmann::json;

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
	std::vector<RoomData> rooms;
};
struct GetPlayersInRoomResponse
{
	std::vector<std::string> players;
};
struct GetHighScoreResponse
{
	unsigned int status;
	std::vector<std::string> statistics;
};
struct GetPersonalStatsResponse
{
	unsigned int status;
	std::vector<std::string> statistics;
};
struct JoinRoomResponse
{
	unsigned int status;
};
struct CreateRoomResponse
{
	unsigned int status;
};
struct CloseRoomResponse
{
	unsigned int status;
};
struct StartGameResponse
{
	unsigned int status;
};
struct GetRoomStateResponse
{
	unsigned int status;
	bool hasGameBegun;
	vector<std::string> players;
	unsigned int questionCount;
	unsigned int answerTimeOut;
};
struct LeaveRoomResponse
{
	unsigned int status;
};


static enum Requests {
	Error = 100,
	Log_In = 101,
	Sign_Up = 102,
	Log_Out = 103,
	Get_Rooms = 104,
	Get_Players = 105,
	Get_Personal_Stats = 106,
	Get_High_Score = 107,
	Join_Room = 108,
	Create_Room = 109,
	Exit = 200,
	Close_Room = 201,
	Start_Game = 202,
	Room_State = 203,
	Leave_Room = 204
};
class JsonResponsePacketSerializer
{
public:
	static unsigned char* serializeErrorResponse(ErrorResponse); 
	static unsigned char* serializeLoginResponse(LoginResponse);
	static unsigned char* serializeSignupResponse(SignupResponse); 
	static unsigned char* serializeResponse(LogoutResponse logRep);
	static unsigned char* serializeResponse(GetRoomsResponse getRoom);
	static unsigned char* serializeResponse(GetPlayersInRoomResponse getPlayers);
	static unsigned char* serializeResponse(JoinRoomResponse joinRoom);
	static unsigned char* serializeResponse(CreateRoomResponse createRoom);
	static unsigned char* serializeResponse(GetHighScoreResponse highScore);
	static unsigned char* serializeResponse(GetPersonalStatsResponse personalStatus);
	static unsigned char* serializeResponse(CloseRoomResponse closeRoom);
	static unsigned char* serializeResponse(StartGameResponse startGame);
	static unsigned char* serializeResponse(GetRoomStateResponse roomState);
	static unsigned char* serializeResponse(LeaveRoomResponse leaveRoom);
	static unsigned char* help(json jsonMSG, std::string mode);
};

