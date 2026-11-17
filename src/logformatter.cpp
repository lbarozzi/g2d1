#include "logformatter.hpp"
#include <format>
#include <chrono>
#include <string>
#include <string_view>

namespace fmt {
    std::string LogFormatter::format(const std::string_view& message) const {
        auto ora = std::chrono::system_clock::now();
        return std::format("{:%Y%m%d %H:%M:%S} ",
                             std::chrono::floor<std::chrono::milliseconds>(ora)) + std::string(message);
    }
} // namespace fmt