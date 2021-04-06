#include "Filesystem.h"

#include <sys/stat.h>

bool RealFileSystem::checkFileExist(const std::string &path) const
{
        struct stat buffer;
        return (stat(path.c_str(), &buffer) == 0);
}