#include <stdio.h>
#include<stdint.h>
#include<inttypes.h>
int main()
{
    uint16_t addr = 10000; // 0b0010011100010000
uint8_t a = ((addr>>16) & (0xff)); 
uint8_t x=10000>> 16 ;
uint8_t y=x & (0xff);

uint8_t b = (((addr>>8) & (0xff)));
uint8_t z=10000>> 8;
uint8_t w=z & (0xff);
printf("%d \n",x);
printf("%d \n",y);
printf("%d \n",z);
printf("%d",w);

}