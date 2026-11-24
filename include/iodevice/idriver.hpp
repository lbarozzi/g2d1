#pragma once
#include <string>
#include <string_view>


namespace iodevice {

class IDriver {
public:
    virtual ~IDriver() = default;
    virtual void sendCommand(const std::string_view& command) = 0;
    virtual std::string getResponse() const = 0;
    virtual std::string getCmdResponse(const std::string_view& command) const = 0;
};

} // namespace iodevice