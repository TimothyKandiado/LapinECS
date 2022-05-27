//
// Created by tmore on 5/26/22.
//

#include "Logger.h"
#include <iostream>
#include <fstream>

namespace Lapin
{
    Logger::~Logger()
    {
        if(!logQueue.empty())
            WriteLogs();
    }
    void Logger::QueueLog(const char * logString)
    {
        logQueue.push(logString);
    }

    void Logger::WriteLogs()
    {
        std::ofstream outFile;
        outFile.open("Log.txt", std::ios::app);
        outFile<<"\n\n[LogEntry]\n";
        while(!logQueue.empty())
        {
            outFile << logQueue.front();
            logQueue.pop();
        }
    }
}