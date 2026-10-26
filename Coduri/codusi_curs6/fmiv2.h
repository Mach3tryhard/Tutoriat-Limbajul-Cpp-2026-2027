#pragma once

#include <fstream>
#include <stdexcept>

class FMIError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class PPTError : public FMIError {
    using FMIError::FMIError;
};
class RoomError : public FMIError {
    using FMIError::FMIError;
};

namespace FMIComputer {
    void loadPPT(const std::string& filePath) {
        std::ifstream fis(filePath);
        if(!fis.good())
            throw PPTError("error opening presentation, file does not exist or is corrupt");
    }
    void findRoom() {
        bool found = false;
        // logica de gasit sala
        if(!found)
            throw RoomError("");
    }
};
