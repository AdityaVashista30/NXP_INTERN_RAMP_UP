#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main(){
uint16_t addr = 10000; 
uint8_t a = ((addr>>16) & (0xff));
// right shift 10000 to 16 bits
// 10000>> 16 = x
// x & (0xff) = y
// x->0b0000000000000000
// value of x is zero
// value of y is zero 

uint8_t b = (((addr>>8) & (0xff)));
// 10000>> 8 = z
// z & (0xff) = w
// z is 0b0000000000100111 which is 39
// w = z&(0x11111111)=z
// w=39
printf("%ld %ld",a,b);

}