#pragma once
#include "IRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "LoginManager.h"

class RequestHandlerFactory;

class LoginRequestHandler : public IRequestHandler
{
public:	
	LoginRequestHandler(RequestHandlerFactory& handleFactory);
	bool isRequestRelevent(RequestInfo reqInfo) override;
	RequestResult handleRequest(RequestInfo reqInfo) override;
private:
	RequestResult login(RequestInfo reqInfo);
	RequestResult signup(RequestInfo reqInfo);
	
	RequestHandlerFactory& m_handleFactory;
};
