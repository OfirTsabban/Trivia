#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(char* buffer)
{
	std::string bufferString = buffer;

	auto json = nlohmann::json::parse(bufferString);

	std::string username = json.at("username");
	std::string password = json.at("password");

	std::cout << "Username: " << username << "pw: "<< password << std::endl;

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

	std::cout << "Username: " << username << "pw: " << password << "Email: " << email << std::endl;

	SignupRequest signupReq = { username, password, email };

	return signupReq;
}
