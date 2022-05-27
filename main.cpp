#include <iostream>
#include "Engine/Engine.h"

int main() {
    Lapin::WindowConfig windowConfig{800, 600, "ECS Engine", false,
                                     60};

    Lapin::Engine engine(&windowConfig);
    Lapin::ENGINE_MODE engineMode = Lapin::PLAYER; // Engine Mode
    engine.Start(engineMode);
}
