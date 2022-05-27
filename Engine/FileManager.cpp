//
// Created by tmore on 5/26/22.
//


#include "FileManager.h"
#include "Utils.h"
#include <sstream>

namespace Lapin
{
    FileManager::FileManager()
    {
        resourceDirectory = "Resources";
        GenerateFileIndex();
    }

    FileManager::FileManager(const char * resourceDirectory)
    {
        this->resourceDirectory = resourceDirectory;
        GenerateFileIndex();
    }

    void FileManager::GenerateFileIndex()
    {
        const filesystem::path pathToShow(resourceDirectory);
        LoopResourceDirectory(pathToShow);
        int numFiles = fileList.size();
        debug.Log("Generated file index with elements: ");
        debug.Log(std::to_string(numFiles));
    }

    void FileManager::LoopResourceDirectory(filesystem::path resourcePath)
    {
        for(const auto& entry: filesystem::directory_iterator(resourcePath))
        {
            if(entry.is_directory())
                LoopResourceDirectory(entry.path());

            else if(entry.is_regular_file())
                AddFileToDictionary(entry);
            else
                debug.LogError("Found unidentified filetype");
        }
    }

    void FileManager::AddFileToDictionary(filesystem::directory_entry fileEntry)
    {
        std::stringstream stringstream;

        std::string filePath = fileEntry.path().string();
        std::string fileName = fileEntry.path().filename().string();

        hashCode fileCode = HashFunction(fileName.c_str());

        fileList.insert(std::pair<hashCode, std::string>(fileCode, filePath));
    }

    std::string FileManager::GetFilePath(std::string fileName)
    {
        hashCode fileNameHash = HashFunction(fileName.c_str());

        auto iter = fileList.find(fileNameHash);
        if(iter == fileList.end())
            debug.Log("File not found in index");

        return iter->second;
    }

    //Debug function to print indexed files
    void FileManager::PrintFileList()
    {
        auto iter = fileList.begin();
        while (iter != fileList.end())
        {
            auto key = iter->first;
            auto value = iter->second;

            std::stringstream stringstream;
            stringstream << "HashCode: " << key << ", Filename: " << value << std::endl;
            debug.Log(stringstream.str().c_str());

            ++iter;
        }
    }
}