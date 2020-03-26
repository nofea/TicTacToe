#include "logger.hpp"

Logger::Logger()
{
}

Logger::~Logger()
{
}

bool Logger::OpenLoggerFile(string sFilePathFile)
{
    bool RetVal = true;

    log.open(sFilePathFile);

    LogMessage("Initializing Logger");
    
    return RetVal;
}

bool Logger::LogMessage(string sMessage)
{
    bool RetVal = true;

    log << ": LOG_MESSAGE: " << sMessage << endl;

    return RetVal;
}


bool Logger::LogMessage(string sMessage, signed int& iTurnCount)
{
    bool RetVal = true;

    log << "TURN: " << iTurnCount << ": LOG_MESSAGE: " << sMessage << endl;

    return RetVal;
}

bool Logger::LogError(string sError, signed int& iTurnCount)
{
    bool RetVal = true;

    log << "TURN: " << iTurnCount << ": LOG_ERROR: " << sError << endl;

    return RetVal;
}

bool Logger::CloseLoggerFile()
{
    log.close();
}