#pragma once
#ifndef IREQUESTHANDLER_H
#define IREQUESTHANDLER_H
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include <iostream>
#include <vector>
#include <ctime>

class IRequestHandler;

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

class IRequestHandler
{
public:
	IRequestHandler();
	virtual bool isRequestRelevant(RequestInfo reqInfo)= 0;
	virtual RequestResult handleRequest(RequestInfo reqInfo) =0 ;
};



#endif // IREQUESTHANDLER_H