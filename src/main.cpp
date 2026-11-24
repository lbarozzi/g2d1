#include <iostream>
#include <memory>
#include <chrono>
#include <format>
#include <string>
#include "g2d1/g2d1.hpp"
#include "Formatter/fakeformatter.hpp"
#include "Formatter/logformatter.hpp"
#include "stdlogger.hpp"
#include "Interfaces/jprotocol.hpp"
#include "iodevice/fifodevice.hpp"

namespace {

constexpr uint8_t kChannels = 4;

// Reads and writes all 4 digital and 4 analog inputs/outputs through the protocol
void exerciseAllIO(const Proto::IProtocol& proto) {
    for (uint8_t pin = 0; pin < kChannels; ++pin) {
        std::cout << "IN"  << int(pin) << " = " << proto.readDigital(pin) << '\n';
    }
    for (uint8_t pin = 0; pin < kChannels; ++pin) {
        std::cout << "AN"  << int(pin) << " = " << proto.readAnalog(pin) << '\n';
    }
    for (uint8_t pin = 0; pin < kChannels; ++pin) {
        std::cout << "OUT" << int(pin) << " <- 1: " << proto.writeDigital(pin, true) << '\n';
    }
    for (uint8_t pin = 0; pin < kChannels; ++pin) {
        std::cout << "PWM" << int(pin) << " <- 128: " << proto.writeAnalog(pin, 128) << '\n';
    }
}

} // namespace

int main(int argc, char* argv[]) {
    //Stampa ora corrente in formato AAAA MM GG HH:MM:SS MSS
    auto ora= std::chrono::system_clock::now();
    std::cout << std::format("{:%Y%m%d %H:%M:%S}", std::chrono::floor<std::chrono::milliseconds>(ora)) << std::endl;

    std::unique_ptr<fmt::IFormatter> formatter = std::make_unique<fmt::LogFormatter>();

    auto logger = std::make_unique<stdlogger::StdLogger>(*formatter);

    logger->log("Hello, world!");

    // Directory holding fifo_in / fifo_out (default: /tmp/jemulator)
    const std::string basePath = argc > 1 ? argv[1] : "/tmp/jemulator";
    try {
        iodevice::FifoDevice device(basePath);
        Proto::JProtocol proto(device);
        exerciseAllIO(proto);
    } catch (const std::exception& e) {
        std::cerr << "Device error (" << basePath << "): " << e.what() << '\n';
    }

    std::cout << g2d1::name << " says: "
       << g2d1::answer() << '\n';

    std::string tmp_text;
    std::cin >> tmp_text;
    
    fmt::FakeFormatter fake;

    std::cout << fake.format(tmp_text) << '\n';
}
