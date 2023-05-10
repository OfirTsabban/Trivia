#include "LoginRequestHandler.h"

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

        RequestResult reqRes = { resp, NULL }; //will change null when new hanlder will be made
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
