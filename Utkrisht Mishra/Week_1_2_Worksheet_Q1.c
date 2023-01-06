#include<stdio.h>

int main(){

    u_int16_t addr = 10000; // 0b0010011100010000
    u_int8_t a = ((addr>>16) & (0xff)); 
    printf("%d \n", a);
    /* 10000>> 16 = x
     right shift by 16 places will give all 0
     this implies x=0;
     x & (0xff) = y
     0 & (0xff) will give y = 0 as AND with all ones will give the same number */

    u_int8_t b = (((addr>>8) & (0xff)));
    printf("%d \n", b);
    /* 10000>> 8 = z
     right shift by 8 places will remove last 8 digits and z will tyhen be equal to 39
     z = 39
     z & (0xff) = w
     39 & (0xff) will give w = 39 as AND with all ones will give the same number.
    */

    return 0;
}