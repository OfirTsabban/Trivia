#pragma once
#include <exception>
#include <iostream>

class ExceptionHandler : public std::exception
{
public:
	ExceptionHandler(const std::string& message) : m_msg(message) {}
	virtual ~ExceptionHandler() noexcept = default;
	virtual const char* what() const noexcept { return m_msg.c_str(); }
protected:
	std::string m_msg;
};