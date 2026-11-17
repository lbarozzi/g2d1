#include <iostream>
#include <memory>
#include <chrono>
#include <format>
#include <string>
#include "g2d1/g2d1.hpp"
#include "Formatter/fakeformatter.hpp"
#include "Formatter/logformatter.hpp"
#include "stdlogger.hpp"

int main() {
    //Stampa ora corrente in formato AAAA MM GG HH:MM:SS MSS
    auto ora= std::chrono::system_clock::now();
    std::cout << std::format("{:%Y%m%d %H:%M:%S}", std::chrono::floor<std::chrono::milliseconds>(ora)) << std::endl;

    std::unique_ptr<fmt::IFormatter> formatter = std::make_unique<fmt::LogFormatter>();

    auto logger = std::make_unique<stdlogger::StdLogger>(*formatter);

    logger->log("Hello, world!");
    std::cout << g2d1::name << " says: "
       << g2d1::answer() << '\n';


    std::string tmp_text;
    std::cin >> tmp_text;
    
    fmt::FakeFormatter fake;

    std::cout << fake.format(tmp_text) << '\n';
}
