#include<stdio.h>
#include<stdint.h>
int main(){
    uint32_t addr = 0; // - 0000 000000 00000 ---- 00000000000 -
    addr = addr | (0xF<<27); 
    printf("%d\n", addr);
    addr = addr | (0xFC<<19); 
    printf("%d\n", addr);
    addr = addr | (0xF8<<13); 
    printf("%d\n", addr);
    addr = addr | (0xFFE); 
    printf("%d\n", addr);
    // output
    return 0;
}