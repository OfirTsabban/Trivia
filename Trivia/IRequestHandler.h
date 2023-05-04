#pragma once
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include <iostream>
#include <vector>
#include <ctime>

class IRequestHandler;

typedef struct RequestInfo
{
	int id;
	std::time_t receivalTime;
	std::vector<unsigned char> buffer;
}RequestInfo;


typedef struct RequestResult
{
	unsigned char* response;
	IRequestHandler* newHandler;
}RequestResult;

class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo reqInfo) = 0;
	virtual RequestResult handleRequest(RequestInfo reqInfo) = 0;
};