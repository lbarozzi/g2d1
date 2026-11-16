#include <cstdlib>

#include "g2d1/g2d1.hpp"

int main() {
    if (g2d1::answer() != 42) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
