#include "Logger.hpp"
#include <ctime>

using namespace std;

/**
 * @brief Construct a new Logger:: Logger object
 * 
 */
Logger::Logger()
{
}

/**
 * @brief Destroy the Logger:: Logger object
 * 
 */
Logger::~Logger()
{
}

/**
 * @brief this function opens/creates a log file
 * 
 * @param sFilePathFile [in] absolute or relative path of the log file to be opened
 * @return true     if a log file was created/opened
 * @return false    if a log file was not created/opened
 */
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

/**
 * @brief this function logs message to the log file
 * 
 * @param sMessage [in] message string
 */
void Logger::LogMessage(const string& sMessage)
{
    log << GetCurrentDateTime() <<":: LOG_MESSAGE: " << sMessage << endl;
}

/**
 * @brief this function logs message to the log file
 * 
 * @param sMessage      [in] message string
 * @param iTurnCount    [in] game turn count
 */
void Logger::LogMessage(const string& sMessage, const signed int& iTurnCount)
{
    log << GetCurrentDateTime() << ":: TURN: " << iTurnCount << ": LOG_MESSAGE: " << sMessage << endl;
}

/**
 * @brief Log error message to log message
 * 
 * @param sError      [in] error message string
 * @param iTurnCount  [in] game turn count
 */
void Logger::LogError(const string& sError, const signed int& iTurnCount)
{
    log << GetCurrentDateTime() << ":: TURN: " << iTurnCount << ": LOG_ERROR: " << sError << endl;
}

/**
 * @brief Log error message to log message
 * 
 * @param sError [in] error message string
 */
void Logger::LogError(const string& sError)
{
    log << GetCurrentDateTime() << ": LOG_ERROR: " << sError << endl;
}

/**
 * @brief closed logger file handler
 * 
 * @return true   if the file is closed successfully 
 * @return false  if the file is not closed successfully
 */
bool Logger::CloseLoggerFile()
{
    log.close();
    return (!log.is_open());
}

/**
 * @brief Returns current system data and time
 * 
 * @return string 
 */
string Logger::GetCurrentDateTime() 
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];    
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d_%m_%Y_%H.%M.%S", &tstruct);

    return buf;
}
