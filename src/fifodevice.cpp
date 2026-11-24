#include "iodevice/fifodevice.hpp"
#include <filesystem>
#include <fstream>
#include <stdexcept>


namespace iodevice {    

    FifoDevice::FifoDevice(const std::string& basePath)
        : basePath_(basePath) {
            if (std::filesystem::exists(basePath)) {
                foStream_.open(basePath_ + ".out", std::ios::out);
                fiStream_.open(basePath_ + ".in", std::ios::in);
            }
            else {
                throw std::runtime_error("FIFO files do not exist");
            }
    }

    void FifoDevice::write(const std::string_view& command) const {
        if (!foStream_.is_open()) {
            throw std::runtime_error("FIFO output stream is not open");
        }
        foStream_ << command << std::endl;
    }

    void FifoDevice::sendCommand(const std::string_view& command) {
        write(command);
    }

    std::string FifoDevice::getResponse() const {
        if (!fiStream_.is_open()) {
            throw std::runtime_error("FIFO input stream is not open");
        }
        std::string response;
        std::getline(fiStream_, response);
        return response;
    }

    std::string FifoDevice::getCmdResponse(const std::string_view& command) const {
        write(command);
        return getResponse();
        
    }

} // namespace iodevice