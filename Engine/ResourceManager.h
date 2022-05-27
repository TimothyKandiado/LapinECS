//
// Created by tmore on 5/26/22.
//

#ifndef LAPINECS_RESOURCEMANAGER_H
#define LAPINECS_RESOURCEMANAGER_H

#include "raylib.h"
#include "flecs.h"
#include "FileManager.h"

namespace Lapin
{
    class ResourceManager
    {
    public:
        ResourceManager(flecs::world *world);
        ~ResourceManager();

        const Image* GetImage(std::string imageName);

        template<class T>
        const T* GetResource(std::string fileName);

    private:
        flecs::world* ecsWorld;
        FileManager fileManager;
        Image GetImageFromFile(std::string imagePath);

        template<class T>
        T GetResourceFromFile(std::string filePath);
    };

}
#endif //LAPINECS_RESOURCEMANAGER_H
