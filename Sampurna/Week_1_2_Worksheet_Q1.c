#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(){
   
    uint16_t addr=1000;
    
    uint8_t x = addr >> 16;
    uint8_t y = ((addr>>16) & (0xff));

    uint8_t z = addr >> 8;
    uint8_t w = (((addr>>8) & (0xff)));

    printf("x = %hhu\ny = %hhu\nz = %hhu\nw = %hhu\n",x,y,z,w);
    return 0;
}
