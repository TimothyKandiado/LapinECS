//
// Created by tmore on 5/26/22.
//

#ifndef LAPINECS_LOGGER_H
#define LAPINECS_LOGGER_H

#include <queue>

namespace Lapin
{
    class Logger
    {
    public:
        ~Logger();
        void QueueLog(const char * logString);
        void WriteLogs();

    private:
        std::queue<const char *> logQueue;
    };
}

#endif //LAPINECS_LOGGER_H
