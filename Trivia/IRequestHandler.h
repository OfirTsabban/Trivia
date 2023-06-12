#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include "Helper.h"

class IRequestHandler;

typedef struct RequestInfo
{
	int id;
	std::time_t recivedTime;
	unsigned char* buffer;
}RequestInfo;

typedef struct RequestResult
{
	unsigned char* response;
	IRequestHandler* newHandler;
}RequestResult;

class IRequestHandler
{
public:
	IRequestHandler();
	~IRequestHandler();

	virtual bool isRequestRelevent(RequestInfo reqInfo) = 0;
	virtual RequestResult handleRequest(RequestInfo reqInfo, SOCKET user_socket) = 0;
};