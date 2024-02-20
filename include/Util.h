#pragma once

#include <string>
#include <chrono>
#include <iostream>

namespace std
{
    inline string to_string(const string &s)
    {
        return s;
    }
}

namespace Util
{

    std::string getLogTimeString();

    void inline print(){};

    template <typename T, typename... Types>
    void print(const T &first, const Types &...args)
    {
        std::cout << first << " ";
        print(args...);
    }

    std::string inline getString() { return ""; };

    template <typename T, typename... Types>
    std::string getString(const T &first, Types &...args)
    {
        std::string result{""};
        result = result + std::to_string(first);
        result += getString(args...);

        return result;
    }

}
