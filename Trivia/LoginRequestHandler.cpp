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
    LoginRequest newUser = JsonRequestPacketDeserializer::deserializeLoginRequest((char*)reqInfo.buffer);
    this->m_handleFactory.getLoginManager().login(newUser.username, newUser.password);
    LoginResponse logResp = { 1 };

    unsigned char* buffer = JsonResponsePacketSerializer::serializeLoginResponse(logResp);
    LoggedUser newUser(newUser.username);

    RequestResult reqRes = { buffer, nullptr };//should be next handler
    return reqRes;
}

RequestResult LoginRequestHandler::Signup(RequestInfo reqInfo)
{
    SignupRequest newUser = JsonRequestPacketDeserializer::deserializeSignupRequest((char*)reqInfo.buffer);
    this->m_handleFactory.getLoginManager().signup(newUser.username, newUser.password, newUser.email, newUser.street, newUser.apt, newUser.city, newUser.prefix, newUser.number, newUser.yearBorn);
    SignupResponse signResp= { 1 };

    unsigned char* buffer = JsonResponsePacketSerializer::serializeSignupResponse(signResp);
    LoggedUser newUser(newUser.username);

    RequestResult reqRes = { buffer, nullptr };//should be next handler
    return reqRes;
}
