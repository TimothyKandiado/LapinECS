//
// Created by tmore on 5/26/22.
//

#include "BaseECSTags.h"
#include "ResourceManager.h"

namespace Lapin
{
    ResourceManager::ResourceManager(flecs::world *world)
    {
        ecsWorld = world;
    }

    ResourceManager::~ResourceManager()
    {

    }

    const Image* ResourceManager::GetImage(std::string imageName)
    {
        const Image* imagePtr;
        auto imageEntity = ecsWorld->lookup(imageName.c_str());

        if(imageEntity)
        {
            imagePtr = imageEntity.get<Image>();
        }
        else
        {
            std::string filePath = fileManager.GetFilePath(imageName);
            Image loadedImage = GetImageFromFile(filePath);
            ImageFormat(&loadedImage, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);

            auto imageEntity = ecsWorld->entity(imageName.c_str());
            imageEntity.set<Image>(loadedImage);

            imagePtr = imageEntity.get<Image>();
        }

        return imagePtr;
    }

    Image ResourceManager::GetImageFromFile(std::string imagePath)
    {
        Image image = LoadImage(imagePath.c_str());

        return image;
    }

    template<class T>
    const T* ResourceManager::GetResource(std::string fileName)
    {
        const T * resourcePointer;
        // look for the Resource entity in the ecs world
        auto resourceEntity = ecsWorld->lookup(fileName.c_str());

        //
        if(resourceEntity)
        {
            resourcePointer = resourceEntity.get<T>();
        }

        else
        {
            std::string filePath = fileManager.GetFilePath(fileName);
            T resource = GetResourceFromFile<T>(filePath);

            auto resourceEntity = ecsWorld->entity(fileName.c_str());
            resourceEntity.add<Resource>();
            resourceEntity.set<T>(resource);

            resourcePointer = resourceEntity.template get<T>();
        }

        return resourcePointer;
    }

    template<>
    Texture ResourceManager::GetResourceFromFile(std::string filePath)
    {
        Texture texture = LoadTexture(filePath.c_str());

        return texture;
    }

    template<>
    Font ResourceManager::GetResourceFromFile(std::string filePath)
    {
        Font font = LoadFont(filePath.c_str());

        return font;
    }

    template<>
    Model ResourceManager::GetResourceFromFile(std::string filePath)
    {
        Model model = LoadModel(filePath.c_str());

        return model;
    }

    template<>
    Image ResourceManager::GetResourceFromFile(std::string filePath)
    {
        Image image = LoadImage(filePath.c_str());
        ImageFormat(&image, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
        return image;
    }


    // defining possible template instantiation
    template const Image* ResourceManager::GetResource<Image>(std::string fileName);
    template const Texture* ResourceManager::GetResource<Texture>(std::string fileName);
    template const Font* ResourceManager::GetResource<Font>(std::string fileName);
    template const Model* ResourceManager::GetResource<Model>(std::string fileName);
    //template const Image* ResourceManager::GetResource<Image>(std::string fileName);

}
