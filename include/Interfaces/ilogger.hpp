#pragma once
#include <string_view>

namespace log {
    class ILogger {
    public:
        virtual ~ILogger() = default;
        virtual void log(const std::string_view& message) const = 0;
    };
} // namespace log