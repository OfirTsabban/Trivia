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
enum action { Error = 0, LogIn = 1, SignUp = 2 };
class JsonResponsePacketSerializer
{
public:
	static unsigned char* serializeErrorResponse(ErrorResponse); 
	static unsigned char* serializeLoginResponse(LoginResponse);
	static unsigned char* serializeSignupResponse(SignupResponse); 
};

