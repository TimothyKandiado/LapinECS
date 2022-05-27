//
// Created by tmore on 5/26/22.
//

#include <cstring>
#include "Types.h"

namespace Lapin
{
    hashCode HashFunction ( const void * key, int len, unsigned int seed )
    {
        const hashCode m = 0xc6a4a7935bd1e995;
        const int r = 47;

        hashCode h = seed ^ (len * m);

        const hashCode * data = (const hashCode *)key;
        const hashCode * end = data + (len/8);

        while(data != end)
        {
            hashCode k = *data++;

            k *= m;
            k ^= k >> r;
            k *= m;

            h ^= k;
            h *= m;
        }

        const unsigned char * data2 = (const unsigned char*)data;

        switch(len & 7)
        {
            case 7: h ^= hashCode(data2[6]) << 48;
            case 6: h ^= hashCode(data2[5]) << 40;
            case 5: h ^= hashCode(data2[4]) << 32;
            case 4: h ^= hashCode(data2[3]) << 24;
            case 3: h ^= hashCode(data2[2]) << 16;
            case 2: h ^= hashCode(data2[1]) << 8;
            case 1: h ^= hashCode(data2[0]);
                h *= m;
        };

        h ^= h >> r;
        h *= m;
        h ^= h >> r;

        return h;
    }

    hashCode HashFunction (const char * key)
    {
        int len = strlen(key);
        uint seed = 31;

        return HashFunction(key, len, seed);
    }
}
