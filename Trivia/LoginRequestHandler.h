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
	RequestResult handleRequest(RequestInfo reqInfo, SOCKET user_socket) override;
private:
	RequestResult login(RequestInfo reqInfo, SOCKET socket);
	RequestResult signup(RequestInfo reqInfo, SOCKET socket);
	
	RequestHandlerFactory& m_handleFactory;
};
