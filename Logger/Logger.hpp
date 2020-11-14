#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <iostream>
#include <fstream>

class Logger
{
private:
    std::ofstream log;
public:
    Logger();
    ~Logger();

public:
    bool OpenLoggerFile(std::string sFilePathName);
    bool LogMessage(std::string sMessage);
    bool LogMessage(std::string sMessage, signed int& iTurnCount);
    bool LogError(std::string sError);
    bool LogError(std::string sError, signed int& iTurnCount);
    bool CloseLoggerFile();
    std::string GetCurrentDateTime();
};

#endif