//
// Created by tmore on 5/26/22.
//

#ifndef LAPINECS_DEBUG_H
#define LAPINECS_DEBUG_H

#include "Logger.h"
#include <string>

namespace Lapin
{
    class Debug
    {
    public:
        Logger logger;

        void Log(const char * str);
        void Log(const std::string &str);
        void LogError(const char * str);
    };

}
#endif //LAPINECS_DEBUG_H
