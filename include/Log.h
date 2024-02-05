#include "Date.h"

namespace Util
{
    class Log
    {
    public:
        enum class Level
        {
            LevelError = 0,
            LevelWarning,
            LevelInfo
        };

    private:
        Level m_LogLevel;
        mutable Date m_date{Date::getCurrentDate()};

    public:
        Log() : m_LogLevel{Level::LevelInfo} {}
        explicit Log(Level level) : m_LogLevel{level} {}

        void SetLogLevel(Level level)
        {
            m_LogLevel = level;
        }
        void Warn(String message) const;
        void Error(String message) const;
        void Info(String message) const;
    };
}