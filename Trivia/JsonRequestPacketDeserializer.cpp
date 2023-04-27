#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(char* buffer)
{
	std::string bufferString = buffer;
	bufferString.substr(41);

	auto json = nlohmann::json::parse(bufferString);

	std::string username = json.at("username");
	std::string password = json.at("password");

	LoginRequest loginReq = { username, password };

	return loginReq;
}
