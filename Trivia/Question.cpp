#include "Question.h"

Question::Question(std::string question, std::string first, std::string second, std::string third, std::string fourth, std::string right)
	:_question(question), _first(first), _second(second), _third(third), _fourth(fourth), _right(right)
{
}

std::string Question::getQuestion()
{
	return this->_question;
}

std::string Question::getAnswers()
{
	return _first + "," + _second + "," + _third + "," + _fourth;
}

std::string Question::getRightAnswer()
{
	return this->_right;
}
