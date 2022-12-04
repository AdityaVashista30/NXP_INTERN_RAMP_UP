// Question after 1st session on C:
//   1) Tell values of x,y,z,w

// uin16_t addr = 10000; // 0b0010011100010000
// uint8_t a = ((addr >> 16) & (0xff));
// // 10000>> 16 = x
// // x & (0xff) = y

// uint8_t b = (((addr >> 8) & (0xff)))
//     // 10000>> 8 = z
//     // z & (0xff) = w

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

/*
    Output:
    10000 >> 16 = 0b0000000000000000 = 0
    therefore, x = 0;
    0 & (0xff) = 0
    therefore, y = 0;

    10000 >> 8 = 0b0000000000100111 = 39
    therefore, z = 39;

    39 & (0xff) = 39;
    therefore w = 39;

*/
