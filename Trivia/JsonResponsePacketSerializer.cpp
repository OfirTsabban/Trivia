#include "JsonResponsePacketSerializer.h"

unsigned char* JsonResponsePacketSerializer::serializeErrorResponse(ErrorResponse ep)
{	
	auto json = nlohmann::json::parse("message:" + ep.message); 
	unsigned char* buffer = new unsigned char(5 + json.size());
	buffer[0] = error;
	int length = json.size();
	buffer[1] = char(&length);
	buffer[5] = json;
	std::cout << buffer << std::endl;
	return buffer;
}

unsigned char* JsonResponsePacketSerializer::serializeLoginResponse(LoginResponse lr)
{
	auto json = nlohmann::json::parse("message:" + lr.status);
	unsigned char* buffer = new unsigned char(5 + json.size());
	buffer[1] = login;
	int length = json.size();
	buffer[1] = char(&length);
	buffer[5] = json;
	std::cout << buffer << std::endl;
	return buffer;
}

unsigned char* JsonResponsePacketSerializer::serializeSignupResponse(SignupResponse sur)
{	
	auto json = nlohmann::json::parse("message:" + sur.status);
	unsigned char* buffer = new unsigned char(5 + json.size());
	buffer[1] = signup;
	int length = json.size();
	buffer[1] = char(&length);
	buffer[5] = json;
	std::cout << buffer << std::endl;
	return buffer;
}
