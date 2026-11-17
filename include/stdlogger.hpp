#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include "Interfaces/ilogger.hpp"
#include "Interfaces/iformatter.hpp"

namespace stdlogger {
    class StdLogger : public log::ILogger {
    public:
        StdLogger() = delete;
        StdLogger(const StdLogger&) = delete;
        StdLogger& operator=(const StdLogger&) = delete;
        ~StdLogger() = default;
        explicit StdLogger(fmt::IFormatter& formatter);
        void log(const std::string_view& message) const override;
            private:
            fmt::IFormatter& m_formatter;
    };
}