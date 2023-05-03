#pragma once
#include <iostream>
#include <vector>
#include <ctime>

struct RequestInfo
{
	int id;
	std::time_t receivalTime;
	std::vector<unsigned char> buffer;
};

struct RequestResult
{
	unsigned char* response;
	IRequestHandler* newHanlder;
};

class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo reqInfo) = 0;
	virtual RequestResult handleRequest(RequestInfo reqInfo) = 0;
};