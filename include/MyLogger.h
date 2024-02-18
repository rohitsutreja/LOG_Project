#pragma once

#include "Log.h"
#include <memory>

namespace MyLogger{

    auto defaultLogger = std::make_shared<Log>();

    std::shared_ptr<Log> getLogger() {
        return defaultLogger;
    }

    void setDefaultLogger(const std::shared_ptr<Log>& logger) {
        defaultLogger = logger;
    }

    void setLevel(Log::Level l) {
        getLogger()->setLevel(l);
    }

    template <typename... Types>
    void debug(const Types&... message)
    {
        getLogger()->log(Log::Level::Debug, message...);
    }

    template <typename... Types>
    void info(const Types&... message)
    {
        getLogger()->log(Log::Level::Info, message...);
    }


    template <typename... Types>
    void warn(const Types&... message)
    {
        getLogger()->log(Log::Level::Warning, message...);

    }

    template <typename... Types>
    void error(const Types&... message)
    {
        getLogger()->log(Log::Level::Error, message...);
    }

    template <typename... Types>
    void critical(const Types&... message)
    {
        getLogger()->log(Log::Level::Critical, message...);
    }
}