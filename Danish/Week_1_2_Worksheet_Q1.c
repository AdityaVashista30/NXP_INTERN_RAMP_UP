#include<stdio.h>
#include<stdint.h>
int main(){
    uint16_t addr = 10000; // 10011100010000
    uint8_t a = ((addr>>16) & (0xFF)); //00000000000000 & 1111 1111
    uint8_t b = ((addr>>8) & (0xFF)); //00100111 & 1111 1111 = 39
    printf("%d\n%d\n", a, b);
    return 0;
}