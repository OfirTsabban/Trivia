#pragma once
#include <fstream>
#include <nlohmann/json.hpp>

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
	unsigned char* serializeErrorResponse(ErrorResponse); 
	unsigned char* serializeLoginResponse(LoginResponse);
	unsigned char* serializeSignupResponse(SignupResponse); 
};

