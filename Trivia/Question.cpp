#include "Question.h"

Question::Question(std::string question, std::string first, std::string second, std::string third, std::string fourth, std::string right)
	:_question(question), _first(first), _second(second), _third(third), _fourth(fourth), _right(right)
{
}

std::string Question::getQuestion()
{
	return this->_question;
}

std::map<unsigned int, std::string> Question::getAnswers()
{
	std::map<unsigned int, std::string> answers;
	answers.insert({ 1, this->_first });
	answers.insert({ 2, this->_second });
	answers.insert({ 3, this->_third });
	answers.insert({ 4, this->_fourth });
	return answers;
}

unsigned int Question::getRightAnswer()
{
	if (_right == _first)
	{
		return 1;
	}
	else if (_right == _second)
	{
		return 2;
	}
	else if (_right == _third)
	{
		return 3;
	}
	else if (_right == _fourth)
	{
		return 4;
	}
}
