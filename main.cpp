#include <iostream>
#include "include\MyLogger.h"

int main()
{
    //Log log;
    //log.setLogLevel(Log::Level::Error);
    //log.Info("Fine!");
    //log.Warn("Carefull!");
    //log.Error("Stop!", String{"Hello"});

 
    MyLogger::setLevel(MyLogger::Log::Level::Info);

    MyLogger::info("Fine!");
    MyLogger::warn("Carefull!");
    MyLogger::error("This is Error");

}
