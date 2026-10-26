#pragma once

#include <fstream>
#include <stdexcept>

class PPTError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

namespace FMIComputer {
    void loadPPT(const std::string& filePath) {
        std::ifstream fis(filePath);
        if(!fis.good())
            throw PPTError("error opening presentation, file does not exist or is corrupt");
    }
};