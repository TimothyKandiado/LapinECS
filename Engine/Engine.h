//
// Created by tmore on 5/26/22.
//

#ifndef LAPINECS_ENGINE_H
#define LAPINECS_ENGINE_H

#include "raylib.h"
#include "flecs.h"

#include "ConstantData.h"
#include "Types.h"
#include "Debug.h"
#include "ResourceManager.h"

namespace Lapin
{
    class Engine
    {
    public:
        Debug debug;
        Engine(WindowConfig* windowConfig);
        ~Engine();
        void Start(ENGINE_MODE engineMode);
        void Stop();

    private:
        // ECS world variable
        flecs::world* ecsWorld;
        ResourceManager* resourceManager;
        void MainLoop();
    };
}

#endif //LAPINECS_ENGINE_H
