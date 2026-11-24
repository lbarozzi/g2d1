#pragma once
#include "idriver.hpp"
#include <fstream>
#include <string>

namespace iodevice {

class FifoDevice : public IDriver {
public:
    FifoDevice(const std::string& basePath);
    void sendCommand(const std::string_view& command) override;
    std::string getResponse() const override;
    std::string getCmdResponse(const std::string_view& command) const override;
    private:
        void write(const std::string_view& command) const;

        std::string basePath_;
        mutable std::ofstream foStream_;
        mutable std::ifstream fiStream_;
};

} // namespace iodevice