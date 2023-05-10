#include "JsonResponsePacketSerializer.h"
#include <string>

using json = nlohmann::json;

unsigned char* JsonResponsePacketSerializer::serializeErrorResponse(ErrorResponse ep)
{	
	auto json = nlohmann::json::parse("message:" + ep.message); 
	unsigned char* buffer = new unsigned char(5 + json.size());
	buffer[0] = error;
	int cut = 1000;
	int length = json.size();
	for (int i = 1; i < 5; i++)
	{
		buffer[i] = json.size() / cut;
		cut /= 10;
	}
	buffer[5] = json;
	std::cout << buffer << std::endl;
	return buffer;
}

unsigned char* JsonResponsePacketSerializer::serializeLoginResponse(LoginResponse lr)
{
	json jsonMSG = { {"message", lr.status} };
	std::string str_json = jsonMSG.dump();
	unsigned char* buffer = new unsigned char((5 + str_json.length() + 1));
	buffer[0] = login;
	int cut = 1000;
	int length = str_json.length();

	for (int i = 1; i < 5; i++)
	{
		buffer[i] = str_json.length() / cut;
		cut /= 10;
	}
	for (int i = 5; i < str_json.length(); i++)
	{
		buffer[i] = str_json[i - 5];
	}

	std::cout << buffer << std::endl;
	return buffer;
}

unsigned char* JsonResponsePacketSerializer::serializeSignupResponse(SignupResponse sur)
{	
	json jsonMSG = { {"message", sur.status} };
	std::string str_json = jsonMSG.dump();
	unsigned char* buffer = new unsigned char(5 + str_json.length() + 1);
	buffer[0] = signup;
	int cut = 1000;
	int length = str_json.length();

	for (int i = 1; i < 5; i++)
	{
		buffer[i] = str_json.length() / cut;
		cut /= 10;
	}
	for (int i = 5; i < str_json.length(); i++)
	{
		buffer[i] = str_json[i - 5];
	}

	std::cout << buffer << std::endl;
	return buffer;
}
