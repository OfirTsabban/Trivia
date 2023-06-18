#include "GameRequestHandler.h"
#include "RequestHandlerFactory.h"

GameRequestHandler::GameRequestHandler(Game& game, LoggedUser& user, RequestHandlerFactory& handlerFactory): m_user(user), m_gameManager(m_handlerFactory.getGameManager()), m_handlerFactory(handlerFactory), m_game(game)
{
}

bool GameRequestHandler::isRequestRelevent(RequestInfo reqInfo)
{
	return reqInfo.id == Leave_Game || reqInfo.id == Get_Question || reqInfo.id == Submit_Answer || reqInfo.id == Get_Game_Result;
}

RequestResult GameRequestHandler::handleRequest(RequestInfo reqInfo, SOCKET user_socket)
{
	switch (reqInfo.id)
	{
	case Leave_Game:
		return leaveGame(reqInfo);
	case Get_Question:
		return getQuestion(reqInfo);
	case Submit_Answer:
		return submitAnswer(reqInfo);
	case Get_Game_Result:
		return getGameResults(reqInfo);
	}
}

RequestResult GameRequestHandler::getQuestion(RequestInfo reqInfo)
{
	Question q = this->m_game.getQuestionForUser(m_user);
	GetQuestionResponse qResp = { 1, q.getQuestion(), q.getAnswers() };

	if (q.getQuestion().length() == 0)
	{
		qResp = { 0, q.getQuestion(), q.getAnswers() };
	}

	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(qResp);
	IRequestHandler* handler = nullptr;
	RequestResult reqResult = { response, handler };
	return reqResult;
}

RequestResult GameRequestHandler::submitAnswer(RequestInfo reqInfo)
{
	SubmitAnswerRequest ansReq = JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest((char*)reqInfo.buffer);
	this->m_gameManager.getGame(this->m_game.getGameId()).submitAnswer(m_user, ansReq.answerId);
	SubmitAnswerResponse ansResp = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(ansResp);
	IRequestHandler* handler = nullptr;
	RequestResult reqResult = { response, handler };
	return reqResult;
}

RequestResult GameRequestHandler::getGameResults(RequestInfo)
{
	GetGameResultsResponse gameRes = { 1, this->m_gameManager.getPlayersResults(this->m_game) };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(gameRes);
	IRequestHandler* handler = m_handlerFactory.createMenuRequestHandler(m_user);
	RequestResult reqResult = { response, handler };
	return reqResult;
}

RequestResult GameRequestHandler::leaveGame(RequestInfo)
{
	this->m_game.removePlayer(m_user);
	LeaveGameResponse leaveResp = { 1 };
	unsigned char* response = JsonResponsePacketSerializer::serializeResponse(leaveResp);
	IRequestHandler* handler = m_handlerFactory.createMenuRequestHandler(m_user);
	RequestResult reqResult = { response, handler };
	return reqResult;
}

