#pragma once
#include <iostream>
#include <map>

class Question
{
public:
	Question(std::string question, std::string first, std::string second, std::string third, std::string fourth, std::string right);
	std::string getQuestion();
	std::map<unsigned int, std::string> getAnswers();
	unsigned int getRightAnswer();

private:
	std::string _question;
	std::string _first;
	std::string _second;
	std::string _third;
	std::string _fourth;
	std::string _right;
};