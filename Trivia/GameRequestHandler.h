#pragma once
#include "IRequestHandler.h"
#include "GameManager.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"

class RequestHandlerFactory;
class GameManager;

class GameRequestHandler : public IRequestHandler
{
public:
	GameRequestHandler(Game& game, LoggedUser& user, RequestHandlerFactory& handlerFactory);
	bool isRequestRelevent(RequestInfo)override;
	RequestResult handleRequest(RequestInfo, SOCKET)override;

private:
	RequestResult getQuestion(RequestInfo);
	RequestResult submitAnswer(RequestInfo);
	RequestResult getGameResults(RequestInfo);
	RequestResult leaveGame(RequestInfo);

	Game& m_game;
	LoggedUser m_user;
	GameManager& m_gameManager;
	RequestHandlerFactory& m_handlerFactory;
};