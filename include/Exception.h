#ifndef EXCEPTION_H
#define EXCEPTION_H

#include"./String.h"

namespace Exception{
	class CustomException {
	private:
		Util::String message{};
	public:
		CustomException(Util::String s) : message{s} {}

		virtual Util::String getMessage() {
			return message;
		}

		virtual ~CustomException(){}

	};


	class StringException: public CustomException{
	public:
		StringException(Util::String s): CustomException{s}{}
	};

	class DateException : public CustomException {
	public:
		DateException(Util::String s) : CustomException{s}{}
	};
}

#endif