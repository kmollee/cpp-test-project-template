#pragma once

#include <string>

class IFileSystem {
    public:
        virtual bool checkFileExist(const std::string &path) const = 0;
};

class RealFileSystem : public IFileSystem {
    public:
        bool checkFileExist(const std::string &path) const override;
};