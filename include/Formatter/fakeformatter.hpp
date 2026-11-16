#pragma once
#include "Interfaces/IFormatter.hpp"
#include <string_view>
#include <string>

namespace fmt {
    class FakeFormatter : public IFormatter {
    public:
        //Retrun reversed text
        std::string format(const std::string_view&  text) const override {
            return std::string(text.rbegin(), text.rend());
        }
    };
} // namespace fmt              