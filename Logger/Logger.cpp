#include "Logger.hpp"
#include <ctime>

using namespace std;

Logger::Logger()
{
}

Logger::~Logger()
{
}

bool Logger::OpenLoggerFile(string sFilePathFile)
{
    bool RetVal = true;

    sFilePathFile += "_" + GetCurrentDateTime() + ".txt";
    
    log.open(sFilePathFile);

    if(log.is_open())
    {
        LogMessage("Initializing Logger");
    }
    else
    {
        RetVal = false;
    }
    
    return RetVal;
}

void Logger::LogMessage(string sMessage)
{
    log << GetCurrentDateTime() <<":: LOG_MESSAGE: " << sMessage << endl;
}


void Logger::LogMessage(string sMessage, signed int& iTurnCount)
{
    log << GetCurrentDateTime() << ":: TURN: " << iTurnCount << ": LOG_MESSAGE: " << sMessage << endl;
}

void Logger::LogError(string sError, signed int& iTurnCount)
{
    log << GetCurrentDateTime() << ":: TURN: " << iTurnCount << ": LOG_ERROR: " << sError << endl;
}

void Logger::LogError(string sError)
{
    log << GetCurrentDateTime() << ": LOG_ERROR: " << sError << endl;
}

bool Logger::CloseLoggerFile()
{
    log.close();
    return (!log.is_open());
}

string Logger::GetCurrentDateTime() 
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];    
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d_%m_%Y_%H.%M.%S", &tstruct);

    return buf;
}
