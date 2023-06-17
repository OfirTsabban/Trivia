#include "LoginRequestHandler.h"
#include "LoginManager.h"
#include "IDatabase.h"
#include "RequestHandlerFactory.h"
#include "ExceptionHandler.h"

LoginRequestHandler::LoginRequestHandler(RequestHandlerFactory& handleFactory) : IRequestHandler(), m_handleFactory(handleFactory)
{
    
}
bool LoginRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
    return reqInfo.id == 101 || reqInfo.id == 102;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo reqInfo, SOCKET user_socket)
{
    if (reqInfo.id == Log_In)
    {
        
        return this->login(reqInfo, user_socket);


    }
    else if (reqInfo.id == Sign_Up)
    {
        
        return this->signup(reqInfo, user_socket);
    }
}

RequestResult LoginRequestHandler::login(RequestInfo reqInfo, SOCKET socket)
{
    LoginRequest newSignUser = JsonRequestPacketDeserializer::deserializeLoginRequest((char*)reqInfo.buffer);
    LoginResponse logResp = { 1 };

    unsigned char* buffer = JsonResponsePacketSerializer::serializeLoginResponse(logResp);   
    IRequestHandler* req;
    try
    {
        this->m_handleFactory.getLoginManager().login(newSignUser.username, newSignUser.password, socket);
        LoggedUser newLogUser(newSignUser.username, socket);
        req = this->m_handleFactory.createMenuRequestHandler(newLogUser);
    }
    catch (ExceptionHandler& exception)
    {
        std::cout << exception.what() << std::endl;
        req = this->m_handleFactory.createLoginRequestHandler();
        logResp = { 0 };
        buffer = JsonResponsePacketSerializer::serializeLoginResponse(logResp);
    }
    RequestResult reqRes = { buffer, req };
    return reqRes;
}

RequestResult LoginRequestHandler::signup(RequestInfo reqInfo, SOCKET socket)
{
    
    SignupRequest newSignUser = JsonRequestPacketDeserializer::deserializeSignupRequest((char*)reqInfo.buffer);
    SignupResponse signResp = { 1 };

    unsigned char* buffer = JsonResponsePacketSerializer::serializeSignupResponse(signResp);   
    IRequestHandler* req;
    try
    {
        
        this->m_handleFactory.getLoginManager().signup(newSignUser.username, newSignUser.password, newSignUser.email, newSignUser.street, newSignUser.apt, newSignUser.city, newSignUser.prefix, newSignUser.number, newSignUser.yearBorn, socket);
        
        LoggedUser newLogUser(newSignUser.username, socket);
        req = this->m_handleFactory.createMenuRequestHandler(newLogUser);
    }
    catch (ExceptionHandler& exception)
    {
        std::cout << exception.what() << std::endl;
        req = this->m_handleFactory.createLoginRequestHandler();
        signResp = { 0 };
        buffer = JsonResponsePacketSerializer::serializeSignupResponse(signResp);
    }

    RequestResult reqRes = { buffer, req };
    return reqRes;
}
