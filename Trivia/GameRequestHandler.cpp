#include "GameRequestHandler.h"

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

RequestResult GameRequestHandler::getQuestion(RequestInfo)
{
	Question q = this->m_game.getQuestionForUser(m_user);

}
