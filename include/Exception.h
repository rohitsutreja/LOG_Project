#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "./String.h"
using Util::String;

namespace Exception
{
    class CustomException
    {
        String message{};

    public:
        CustomException(String s) : message{ s }
        {
        }
    };
}

#endif