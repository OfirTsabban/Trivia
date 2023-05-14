#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
class LoginRequestHandler : public IRequestHandler
{
public:
	bool isRequestRelevant(RequestInfo reqInfo) override;
	RequestResult handleRequest(RequestInfo reqInfo) override;
private:
	RequestHandlerFactory& m_handleFactory;
	RequestResult login(RequestInfo reqInfo);
	RequestResult signup(RequestInfo reqInfo);
};