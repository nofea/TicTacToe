#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <iostream>
#include <fstream>

/**
 * @brief holds elements used for logging purposes
 * 
 */
class Logger
{
private:
    std::ofstream log;
public:
    Logger();
    ~Logger();

public:
    bool OpenLoggerFile(std::string sFilePathName);
    void LogMessage(const std::string& sMessage);
    void LogMessage(const std::string& sMessage, const signed int& iTurnCount);
    void LogError(const std::string& sError);
    void LogError(const std::string& sError, const signed int& iTurnCount);
    bool CloseLoggerFile();
    std::string GetCurrentDateTime();
};

#endif
