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
	std::string street;
	std::string apt;
	std::string city;
	std::string prefix;
	std::string number;
	std::string yearBorn;
};

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(char* buffer);
	static SignupRequest deserializeSignupRequest(char* buffer);
};