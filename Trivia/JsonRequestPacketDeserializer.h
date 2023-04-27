#pragma once
#include <iostream>
#include "json.hpp"

struct LoginRequest 
{
	std::string username;
	std::string password;
};

struct SignupRequest
{
	std::string username;
	std::string password;
	std::string email;
};

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(char* buffer);
	static SignupRequest deserializeSignupRequest(char* buffer);
};