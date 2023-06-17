#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(char* buffer)
{
	std::string bufferString = buffer;
	bufferString = bufferString.substr(bufferString.find("{"));
	auto json = nlohmann::json::parse(bufferString);

	std::string username = json.at("username");
	std::string password = json.at("password");

	std::cout << "Username: " << username << ", pw: "<< password << std::endl;

	LoginRequest loginReq = { username, password };

	return loginReq;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(char* buffer)
{
	std::string bufferString = buffer;
	bufferString = bufferString.substr(bufferString.find("{"));
	auto json = nlohmann::json::parse(bufferString);

	std::string username = json.at("username");
	std::string password = json.at("password");
	std::string email = json.at("email");
	std::string street = json.at("street");
	std::string apt = json.at("apt");
	std::string city = json.at("city");
	std::string prefix = json.at("prefix");
	std::string number = json.at("number");
	std::string yearBorn = json.at("year");

	std::cout << "Username: " << username << ", pw: " << password << ", Email: " << email << std::endl;

	SignupRequest signupReq = { username, password, email, street, apt, city, prefix, number, yearBorn };

	return signupReq;
}

GetPlayersInRoomRequest JsonRequestPacketDeserializer::deserializeGetPlayersRequest(char* buffer)
{
	std::string bufferString = buffer;
	bufferString = bufferString.substr(bufferString.find("{"));
	auto json = nlohmann::json::parse(bufferString);

	GetPlayersInRoomRequest players = { json.at("roomID") };
	return players;
}

JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(char* buffer)
{
	std::string bufferString = buffer;
	bufferString = bufferString.substr(bufferString.find("{"));
	auto json = nlohmann::json::parse(bufferString);

	JoinRoomRequest joinReq = { json.at("roomID") };
	return joinReq;
}

CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(char* buffer)
{
	std::string bufferString = buffer;
	bufferString = bufferString.substr(bufferString.find("{"));
	auto json = nlohmann::json::parse(bufferString);

	CreateRoomRequest roomReq = { json.at("roomName"), json.at("maxUsers"), json.at("questionCount"), json.at("answerTimeout") };
	return roomReq;
}
