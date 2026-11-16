#pragma once
#include <string>


namespace fmt {
    class IFormatter {
        
    public:
        virtual ~IFormatter() = default;
        virtual std::string format(const std::string_view&  text) const = 0;
    };
} // namespace fmt