#pragma once
#include "Interfaces/iformatter.hpp"
#include <string>
#include <string_view>

namespace fmt {
    class LogFormatter : public IFormatter {
    public:
        // Prefixes the text with the current timestamp
        std::string format(const std::string_view& message) const override;
    };
} // namespace fmt
