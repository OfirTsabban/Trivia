#include "JsonResponsePacketSerializer.h"
#include <string>

using json = nlohmann::json;

unsigned char* JsonResponsePacketSerializer::serializeErrorResponse(ErrorResponse ep)
{	
	auto json = nlohmann::json::parse("message:" + ep.message); 
	unsigned char* buffer = new unsigned char(5 + json.size());
	buffer[0] = Error;
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
	json jsonMSG = { {"status", lr.status} };
	std::string str_json = jsonMSG.dump();
	
	std::string s = std::to_string(LogIn);
	int cut = 1000;
	int length = str_json.length();	
	//std::cout << str_json
	std::string len = std::to_string(str_json.length());
	while (len.length() < 4)
	{
		len = "0" + len;
	}
	s += len;
	for (int i = 0; i < str_json.length(); i++)
	{
		s += str_json[i];
	}
	unsigned char* buffer = new unsigned char[(s.length()+1)];
	std::copy(s.begin(), s.end(), buffer);
	buffer[s.length()] = 0;
	std::cout << std::endl << buffer << std::endl;
	return buffer;
}

unsigned char* JsonResponsePacketSerializer::serializeSignupResponse(SignupResponse sur)
{	
	json jsonMSG = { {"status", sur.status} };
	std::string str_json = jsonMSG.dump();

	std::string s = std::to_string(SignUp);
	int cut = 1000;
	int length = str_json.length();
	std::string len = std::to_string(str_json.length());
	while (len.length() < 4)
	{
		len = "0" + len;
	}
	s += len;
	for (int i = 0; i < str_json.length(); i++)
	{
		s += str_json[i];
	}
	unsigned char* buffer = new unsigned char[(s.length() + 1)];
	std::copy(s.begin(), s.end(), buffer);
	buffer[s.length()] = 0;
	std::cout << std::endl << buffer << std::endl; 
	return buffer;
}
