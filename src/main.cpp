#include <iostream>
#include <memory>
#include "g2d1/g2d1.hpp"
#include "Formatter/fakeformatter.hpp"

int main() {
    std::cout << g2d1::name << " says: "
       << g2d1::answer() << '\n';
    std::string tmp_text;
    std::cin >> tmp_text;
    
    std::unique_ptr<fmt::IFormatter> formatter = std::make_unique<fmt::FakeFormatter>();

    std::cout << formatter->format(tmp_text) << '\n';
}
