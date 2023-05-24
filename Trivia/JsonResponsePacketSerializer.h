#pragma once
#include <iostream>
#include "json.hpp"

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
};

