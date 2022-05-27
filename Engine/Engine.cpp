//
// Created by tmore on 5/26/22.
//

#include "Engine.h"
#include "FileManager.h"

namespace Lapin
{
    Engine::Engine(WindowConfig *windowConfig) // Constructor
    {
        /*Initiate Graphics*/
        // Set window Parameters
        InitWindow(windowConfig->screenWidth, windowConfig->screenHeight, windowConfig->windowTitle);
        //Set Target FPS of Engine
        SetTargetFPS(windowConfig->FPS);
        if(windowConfig->fullScreen)
            SetWindowState(FLAG_FULLSCREEN_MODE);

        /*Initiate ECS*/
        ecsWorld = new flecs::world();
        resourceManager = new ResourceManager(ecsWorld);
        debug.Log("Engine Initialised");

        const Image* image = resourceManager->GetResource<Image>("raylib_logo.png");
        SetWindowIcon(*image);
    }

    Engine::~Engine() // Destructor
    {
        debug.Log("Engine Closed");
        delete(resourceManager);
        delete(ecsWorld);
        CloseWindow();
    }

    void Engine::Start(ENGINE_MODE engineMode)
    {
        debug.Log("Starting MainLoop");
        while (!WindowShouldClose())
        {
            MainLoop();
        }
    }

    void Engine::MainLoop()
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10,10);
        DrawText("Lapin ECS Initialise", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }


}