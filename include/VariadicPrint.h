#ifndef PRINT_H
#define PRINT_H

#include "String.h"

void inline print() {}

template <typename T, typename... Types>
void print(const T& first, const Types&... args)
{
    std::cout << first << " ";
    print(args...);
}



Util::String inline getString() { return ""; };

template <typename T, typename... Types>
Util::String getString(const T& first, Types&... args)
{
    Util::String result{ "" };
    result.append(Util::String::toString(first));
    result.append(getString(args...));

    return result;
}


#endif