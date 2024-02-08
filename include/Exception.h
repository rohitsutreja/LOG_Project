#include "String.h"

using Util::String;

namespace Exception
{
    class CustomException
    {

        String message{};

    public:
        CustomException(String s) : message{s}
        {
        }
    };
}