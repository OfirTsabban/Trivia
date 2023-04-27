#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(char* buffer)
{
	std::string bufferString = buffer;

	auto json = nlohmann::json::parse(bufferString);

	std::string username = json.at("username");
	std::string password = json.at("password");

	LoginRequest loginReq = { username, password };

	return loginReq;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(char* buffer)
{
	std::string bufferString = buffer;

	auto json = nlohmann::json::parse(bufferString);

	std::string username = json.at("username");
	std::string password = json.at("password");
	std::string email = json.at("email");

	SignupRequest signupReq = { username, password, email };

	return signupReq;
}
