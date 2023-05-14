#include "LoginRequestHandler.h"
#include "LoginManager.h"
#include "IDatabase.h"
bool LoginRequestHandler::isRequestRelevant(RequestInfo reqInfo)
{
    return reqInfo.id == 1 || reqInfo.id == 2;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo reqInfo)
{
    if (reqInfo.id == login)
    {
        LoginResponse loginResp = { 1 };
        unsigned char* resp = JsonResponsePacketSerializer::serializeLoginResponse(loginResp);
        LoginRequestHandler* logReq;
        //try
        //{
        //    this->m_handleFactory.getLoginManager().login();
        //    logReq = this->m_handleFactory.createLoginRequestHandler();
        //}
        //catch (/*exception e*/)
        //{
        //    logReq = nullptr;
        //}
        // need to wait for your exception;         
        RequestResult reqRes = { resp, logReq };
        return reqRes;
    }
    else if (reqInfo.id == signup)
    {
        SignupResponse signUpResp = { 2 };
        unsigned char* resp = JsonResponsePacketSerializer::serializeSignupResponse(signUpResp);

        RequestResult reqRes = { resp, NULL }; //will change null when new hanlder will be made
        return reqRes;
    }
}
