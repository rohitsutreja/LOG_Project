#include <iostream>
#include "include\MyLogger.h"

int main()
{
    MyLogger::setLevel(MyLogger::Log::Level::Info);
    MyLogger::info("Fine!");
    MyLogger::warn("Carefull!");
    MyLogger::error("This is Error");
    MyLogger::info("Fine!");
    MyLogger::warn("Carefull!");
    MyLogger::error("This is Error");
    MyLogger::info("Fine!");
    MyLogger::warn("Carefull!");
    MyLogger::error("This is Error");
}
