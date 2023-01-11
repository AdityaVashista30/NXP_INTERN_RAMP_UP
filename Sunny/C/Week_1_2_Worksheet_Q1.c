#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t addr = 10000; // 0b0010011100010000
    uint8_t a = ((addr >> 16) & (0xff));
    // 10000 >> 16 = x;
    // x & (0xff) = y;

    uint8_t b = ((addr >> 8) & (0xff));
    // 10000 >> 8 = z;
    // z & (0xff) = w;

    return 0;
}