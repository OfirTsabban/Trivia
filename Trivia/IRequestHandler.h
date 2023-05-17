#pragma once
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include <iostream>
#include <vector>
#include <ctime>

struct RequestResult;
struct RequestInfo;

class IRequestHandler
{
public:
	IRequestHandler();
	~IRequestHandler();
	virtual bool isRequestRelevant(RequestInfo reqInfo) = 0;
	virtual RequestResult handleRequest(RequestInfo reqInfo) = 0;
};

typedef struct RequestResult
{
	unsigned char* response;
	IRequestHandler* newHandler;
}RequestResult;

typedef struct RequestInfo
{
	int id;
	std::time_t receivalTime;
	unsigned char* buffer;
}RequestInfo;