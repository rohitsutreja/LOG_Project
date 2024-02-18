#include "Date.h"
#include "VariadicPrint.h"
#include "FileWriter.h"
//#include <Windows.h>

#ifndef LOG_H
#define LOG_H

using Util::Date;
using Util::String;
using Util::FileWriter;


namespace MyLogger

{
    class Log
    {
    public:
        enum class Level
        {   
            Debug = 0,
            Info,
            Warning,
            Error,
            Critical
        };

    private:
        Level m_LogLevel;
        bool m_dumpInFile{ true };
        String m_fPath{ "log.txt" };
        mutable String m_buffer{ };
        mutable int m_bufferCount{};


    public:
        Log() : m_LogLevel{ Level::Info } {}
        explicit Log(Level level, String filePath) : m_LogLevel{ level }, m_fPath{filePath} {}

        void setLevel(Level level) { m_LogLevel = level; }
        void setFilePath(String path) { m_fPath = path; }
        void setDumpInFileFlag(bool f) { m_dumpInFile = f; }

        constexpr Level getLevel() const { return m_LogLevel; }
        String getLevelName(Level l) const;
        String getColoredLevelName(Level l) const;

        void logOnConsole(const String& msg) const;
        void logOnFile(const String& msg, const String& fileName) const;
        void flushOnFile() const;

        ~Log();


        template <typename... Types>
        void log(Level level, const Types&... message) const
        {
            if (level >= m_LogLevel)
            {
                String dateStringRep = "Date: " + Date::getCurrentDate().getStringRep();
                String messageStringRep = getString(message...);
                String finalMessageForConsole = dateStringRep + " " + getColoredLevelName(level) + " " + messageStringRep + "\n";
                String finalMessageForFile = dateStringRep + " [" + getLevelName(level) + "] " + messageStringRep + "\n";
                
                logOnConsole(finalMessageForConsole);

                if(m_dumpInFile == true)
                {  
                    m_buffer.append(finalMessageForFile);
                    ++m_bufferCount;
                    if (m_bufferCount >= 10) {

                        flushOnFile();

                    } 
                }
                
            }
        }
    };

}

#endif