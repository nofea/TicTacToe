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

    sFilePathFile += "_" + GetCurrentDateTime()+".txt";
    
    log.open(sFilePathFile);
    LogMessage("Initializing Logger");
    
    return RetVal;
}

bool Logger::LogMessage(string sMessage)
{
    bool RetVal = true;

    log << GetCurrentDateTime() <<":: LOG_MESSAGE: " << sMessage << endl;

    return RetVal;
}


bool Logger::LogMessage(string sMessage, signed int& iTurnCount)
{
    bool RetVal = true;

    log << GetCurrentDateTime() << ":: TURN: " << iTurnCount << ": LOG_MESSAGE: " << sMessage << endl;

    return RetVal;
}

bool Logger::LogError(string sError, signed int& iTurnCount)
{
    bool RetVal = true;

    log << GetCurrentDateTime() << ":: TURN: " << iTurnCount << ": LOG_ERROR: " << sError << endl;

    return RetVal;
}

bool Logger::CloseLoggerFile()
{
    log.close();
}

const string Logger::GetCurrentDateTime() 
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y.%X", &tstruct);

    return buf;
}