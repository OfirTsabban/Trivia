#include "LoginRequestHandler.h"
#include "LoginManager.h"
#include "IDatabase.h"
#include "RequestHandlerFactory.h"

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
    LoginRequest newSignUser = JsonRequestPacketDeserializer::deserializeLoginRequest((char*)reqInfo.buffer);
    this->m_handleFactory.getLoginManager().login(newSignUser.username, newSignUser.password);

    LoginResponse logResp = { 1 };

    unsigned char* buffer = JsonResponsePacketSerializer::serializeLoginResponse(logResp);
    LoggedUser newLogUser(newSignUser.username);
    IRequestHandler* req = this->m_handleFactory.createLoginRequestHandler();
    
    RequestResult reqRes = { buffer, req };
    return reqRes;
}

RequestResult LoginRequestHandler::Signup(RequestInfo reqInfo)
{
    SignupRequest newSignUser = JsonRequestPacketDeserializer::deserializeSignupRequest((char*)reqInfo.buffer);
    this->m_handleFactory.getLoginManager().signup(newSignUser.username, newSignUser.password, newSignUser.email, newSignUser.street, newSignUser.apt, newSignUser.city, newSignUser.prefix, newSignUser.number, newSignUser.yearBorn);
    SignupResponse signResp= { 1 };

    unsigned char* buffer = JsonResponsePacketSerializer::serializeSignupResponse(signResp);
    LoggedUser newLogUser(newSignUser.username);
    IRequestHandler* req = this->m_handleFactory.createLoginRequestHandler();

    RequestResult reqRes = { buffer, req };
    return reqRes;
}
