#include <iostream>
#include "..\include\Log.h"

using Util::Log;

void Log::Warn(String message) const
{
    if (m_LogLevel >= Level::LevelWarning)
    {
        m_date.refreshDate();
        std::cout << "[Warning]: " << message << " - Date: " << m_date.getStringRep() << '\n';
    }
}
void Log::Error(String message) const
{
    if (m_LogLevel >= Level::LevelError)
    {
        m_date.refreshDate();
        std::cout << "[Error]: " << message << " - Date: " << m_date.getStringRep() << '\n';
    }
}
void Log::Info(String message) const
{
    if (m_LogLevel >= Level::LevelInfo)
    {
        m_date.refreshDate();
        std::cout << "[Info]: " << message << " - Date: " << m_date.getStringRep() << '\n';
    }
}