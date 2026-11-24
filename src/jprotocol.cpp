#include "Interfaces/jprotocol.hpp"

namespace Proto {

    JProtocol::JProtocol(iodevice::IDriver& device)
        : device_(device) {
    }
    std::string JProtocol::readDigital(uint8_t pin) const {
        return device_.getCmdResponse("get IN" + std::to_string(pin));
    }

    std::string JProtocol::readAnalog(uint8_t pin) const {
        return device_.getCmdResponse("get AN" + std::to_string(pin));
    }

    std::string JProtocol::writeDigital(uint8_t pin, bool state) const {
        return device_.getCmdResponse("set OUT" + std::to_string(pin) + " " + (state ? "1" : "0"));
    }

    std::string JProtocol::writeAnalog(uint8_t pin, int value) const {
        return device_.getCmdResponse("set PWM" + std::to_string(pin) + " " + std::to_string(value));
    }

} // namespace Proto