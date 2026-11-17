#pragma once
#include "Interfaces/iformatter.hpp"    

namespace fmt {
    class LogFormatter : public IFormatter {
    public:
        LogFormatter() = default;
        LogFormatter(const LogFormatter&) = delete;
        LogFormatter& operator=(const LogFormatter&) = delete;
        ~LogFormatter() = default;
        std::string format(const std::string_view& message) const override;
    };
} // namespace fmt