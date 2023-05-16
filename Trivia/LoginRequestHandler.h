#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler(RequestHandlerFactory& handleFactory);
	bool isRequestRelevant(RequestInfo reqInfo) override;
	RequestResult handleRequest(RequestInfo reqInfo) override;
private:
	RequestHandlerFactory& m_handleFactory;
	RequestResult Login(RequestInfo reqInfo);
	RequestResult Signup(RequestInfo reqInfo);
};