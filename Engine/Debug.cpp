//
// Created by tmore on 5/26/22.
//

#include "Debug.h"
#include <iostream>

namespace Lapin
{
    void Debug::Log(const char * str)
    {
#ifdef DEBUG_ENABLED
        std::cout << str << std::endl;
#ifdef DEBUG_LOGGING_ENABLED
        logger.QueueLog(str);
        logger.QueueLog("\n");
#endif
#endif
    }

    void Debug::Log(const std::string& string)
    {
#ifdef DEBUG_ENABLED
        std::cout << string << std::endl;
#endif
    }

    void Debug::LogError(const char *str)
    {
#ifdef DEBUG_ENABLED
        std::cerr << str << std::endl;
#ifdef DEBUG_LOGGING_ENABLED
        logger.QueueLog(str);
        logger.QueueLog("\n");
#endif
#endif
    }


}