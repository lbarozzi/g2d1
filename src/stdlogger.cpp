#include "stdlogger.hpp"
#include <format>   

namespace stdlogger {

StdLogger::StdLogger(fmt::IFormatter& formatter) : m_formatter(formatter) {}

void StdLogger::log(const std::string_view& message) const {
    std::cerr << m_formatter.format(message) << std::endl;
}

} // namespace stdloggerh

