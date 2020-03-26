#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <iostream>
#include <fstream>

using namespace std;

class Logger
{
private:
    ofstream log;
public:
    Logger();
    ~Logger();

public:
    bool OpenLoggerFile(string sFilePathName);
    bool LogMessage(string sMessage);
    bool LogMessage(string sMessage, signed int& iTurnCount);
    bool LogError(string sError, signed int& iTurnCount);
    bool CloseLoggerFile();
};

#endif