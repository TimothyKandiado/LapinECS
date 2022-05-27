//
// Created by tmore on 5/26/22.
//

#ifndef LAPINECS_FILEMANAGER_H
#define LAPINECS_FILEMANAGER_H

#include <filesystem>
#include <map>

#include "raylib.h"
#include "Types.h"
#include "Debug.h"
#include <string>

namespace Lapin
{
    namespace filesystem = std::filesystem;

    class FileManager
    {
    public:
        //Constructors
        FileManager();
        explicit FileManager(const char * resourceDirectory);
        //FileManager(const char * zipFileName);

        //Index Resource Directory
        void GenerateFileIndex();

        std::string GetFilePath(std::string fileName);
        std::string GetFilePath(hashCode hashcode);

    private:
        std::map <hashCode, std::string> fileList;

        const char * resourceDirectory;
        Debug debug;

        void LoopResourceDirectory(filesystem::path resourcePath);
        void AddFileToDictionary(filesystem::directory_entry fileEntry);

        void PrintFileList();
    };
}

#endif //LAPINECS_FILEMANAGER_H
