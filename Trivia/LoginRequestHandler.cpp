#include "LoginRequestHandler.h"
#include "LoginManager.h"
#include "IDatabase.h"
LoginRequestHandler::LoginRequestHandler(RequestHandlerFactory& handleFactory) : IRequestHandler(), m_handleFactory(handleFactory)
{
    
}
bool LoginRequestHandler::isRequestRelevant(RequestInfo reqInfo)
{
    return reqInfo.id == 1 || reqInfo.id == 2;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo reqInfo)
{
    if (reqInfo.id == login)
    {
        
        return this->Login(reqInfo);


    }
    else if (reqInfo.id == signup)
    {
        
        return this->Signup(reqInfo);
    }
}

RequestResult LoginRequestHandler::Login(RequestInfo reqInfo)
{
    LoginResponse loginResp = { 1 };
    unsigned char* resp = JsonResponsePacketSerializer::serializeLoginResponse(loginResp);

    //need to wait for your exception;         
    RequestResult reqRes;
    LoginRequestHandler* logReq;
    try
    {
        logReq =

    }
    catch (/*exception e*/)
    {
        logReq = nullptr;
    }
}

RequestResult LoginRequestHandler::Signup(RequestInfo reqInfo)
{
    SignupResponse signUpResp = { 2 };
    unsigned char* resp = JsonResponsePacketSerializer::serializeSignupResponse(signUpResp);

    RequestResult reqRes = { resp, NULL }; //will change null when new hanlder will be made
}
