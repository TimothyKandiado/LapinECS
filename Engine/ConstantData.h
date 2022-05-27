//
// Created by tmore on 5/26/22.
//

#ifndef LAPINECS_CONSTANTDATA_H
#define LAPINECS_CONSTANTDATA_H

#include "Types.h"

namespace Lapin
{
    struct WindowConfig
    {
        const uint screenWidth;
        const uint screenHeight;
        const char* windowTitle;
        const bool fullScreen;
        const uint FPS;
        const bool MSAA_4X;
        const bool VSYNC;
    };
}

#endif //LAPINECS_CONSTANTDATA_H
