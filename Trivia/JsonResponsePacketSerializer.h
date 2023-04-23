#pragma once
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

class JsonResponsePacketSerializer
{
public:
	unsigned char* serializeResponse(ErrorResponse); 
	unsigned char* serializeResponse(LoginResponse);
	unsigned char* serializeResponse(SignupResponse);
};

