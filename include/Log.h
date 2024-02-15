#include "Date.h"
#include "VariadicPrint.h"

#ifndef LOG_H
#define LOG_H

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

        template <typename... Types>
        void Warn(Types... message) const
        {
            if (m_LogLevel >= Level::LevelWarning)
            {
                m_date.refreshDate();
                std::cout << "[Warning]: ";
                print(message...);
                std::cout << " - Date: " << m_date.getStringRep() << '\n';
            }
        }

        template <typename... Types>
        void Error(Types... message) const
        {
            if (m_LogLevel >= Level::LevelError)
            {
                m_date.refreshDate();
                std::cout << "[Error]: ";
                print(message...);
                std::cout << " - Date: " << m_date.getStringRep() << '\n';
            }
        }

        template <typename... Types>
        void Info(Types... message) const
        {

            if (m_LogLevel >= Level::LevelInfo)
            {
                m_date.refreshDate();
                std::cout << "[Info]: ";
                print(message...);
                std::cout << " - Date: " << m_date.getStringRep() << '\n';
            }
        }

    };
}

#endif