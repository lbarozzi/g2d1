#pragma once
#include <string>
#include <cstdint>

namespace Proto {
    class IProtocol {
    public:
        virtual ~IProtocol() = default;
        virtual std::string readDigital(uint8_t pin) const = 0;
        virtual std::string readAnalog(uint8_t pin) const = 0;
        virtual std::string writeDigital(uint8_t pin, bool state) const = 0;
        virtual std::string writeAnalog(uint8_t pin, int  value) const = 0;
    };

} // namespace Proto