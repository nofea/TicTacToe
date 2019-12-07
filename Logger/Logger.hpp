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
    bool LogError(string sError);
    bool CloseLoggerFile();
};

#endif