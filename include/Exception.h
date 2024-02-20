
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

namespace Exception
{
	class CustomException
	{
	private:
		std::string message{};

	public:
		CustomException(std::string s) : message{s} {}

		virtual std::string getMessage()
		{
			return message;
		}

		virtual ~CustomException() {}
	};

	class StringException : public CustomException
	{
	public:
		StringException(std::string s) : CustomException{s} {}
	};

	class DateException : public CustomException
	{
	public:
		DateException(std::string s) : CustomException{s} {}
	};
}

#endif