#include "LoginRequestHandler.h"

bool LoginRequestHandler::isRequestRelevant(RequestInfo reqInfo)
{
    return reqInfo.id == 1 || reqInfo.id == 2;
}
