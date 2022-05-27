//
// Created by tmore on 5/26/22.
//

#ifndef LAPINECS_UTILS_H
#define LAPINECS_UTILS_H

#include "Types.h"

namespace Lapin
{
    // Implementation by Austin Appleby in MurmurHash64A
    hashCode HashFunction (const void * key, int len, unsigned int seed );
    hashCode HashFunction (const char * key);
}

#endif //LAPINECS_UTILS_H
