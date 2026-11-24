#pragma once
#include <cstdint>
#include <string>
#include "iprotocol.hpp"
#include "iodevice/idriver.hpp"

namespace Proto {

    class JProtocol: public IProtocol {
    public:
        explicit JProtocol(iodevice::IDriver& device);
        ~JProtocol() override = default;
        std::string readDigital(uint8_t pin) const override;
        std::string readAnalog(uint8_t pin) const override;
        std::string writeDigital(uint8_t pin, bool state) const override;
        std::string writeAnalog(uint8_t pin, int value) const override;

    protected:
        iodevice::IDriver& device_;
    };

} // namespace Proto