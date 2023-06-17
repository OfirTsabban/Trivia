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

struct GetPlayersInRoomRequest
{
	unsigned int roomId;
};

struct CreateRoomRequest
{
	std::string roomName;
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int answerTimeout;
};

struct JoinRoomRequest
{
	unsigned int roomId;
};

struct SubmitAnswerRequest
{
	unsigned int answerId;
};

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(char* buffer);
	static SignupRequest deserializeSignupRequest(char* buffer);
	static GetPlayersInRoomRequest deserializeGetPlayersRequest(char* buffer);
	static JoinRoomRequest deserializeJoinRoomRequest(char* buffer);
	static CreateRoomRequest deserializeCreateRoomRequest(char* buffer);
	static SubmitAnswerRequest deserializeSubmitAnswerRequest(char* buffer);

};