#include <iostream>
#include "include\Log.h"
#include "include\String.h"
#include "include\Date.h"

using Util::Date;
using Util::Log;
using Util::String;

int main()
{
    Log log;
    log.SetLogLevel(Log::Level::LevelError);
    log.Info("Fine!");
    log.Warn("Carefull!");
    log.Error("Stop!");

}
