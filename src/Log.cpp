#include <iostream>
#include "..\include\Log.h"

using MyLogger::Log;

String Log::getLevelName(Level l) const {

    switch (l) {
    case Level::Error:
        return "Error";

    case Level::Warning:
        return "Warning";

    case Level::Info:
        return "Info";

    case Level::Debug:
        return "Debug";

    case Level::Critical:
        return "Critical";
    }
}

String Log::getColoredLevelName(Level l) const {

    switch (l) {
    case Level::Error:
        return "\033[31m[Error]\033[0m";

    case Level::Warning:
        return "\033[33m[Warning]\033[0m";

    case Level::Info:
        return "\033[32m[Info]\033[0m";

    case Level::Debug:
        return "Debug";

    case Level::Critical:
        return "\033[41;37m[Critical]\033[0m";
    }
}

void Log::logOnConsole(const String& msg) const {
    std::cout << msg;
}

void Log::logOnFile(const String& msg, const String& fileName) const {
    FileWriter fw{ fileName };
    fw.writeLine(msg);
}

void Log::flushOnFile() const {
    if (m_buffer != "") {
        logOnFile(m_buffer, m_fPath);
        m_buffer = "";
    }
}

Log::~Log() {
    if (m_buffer != "") {
        logOnFile(m_buffer, m_fPath);
        m_buffer = "";
    }
}