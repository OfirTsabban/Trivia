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
enum action { error = 0, login = 1, signup = 2 };
class JsonResponsePacketSerializer
{
public:
	unsigned char* serializeErrorResponse(ErrorResponse); 
	unsigned char* serializeLoginResponse(LoginResponse);
	unsigned char* serializeSignupResponse(SignupResponse); 
};

