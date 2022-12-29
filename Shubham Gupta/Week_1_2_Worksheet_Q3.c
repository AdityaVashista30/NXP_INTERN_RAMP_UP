#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t a =63002; //1111011000011010
    uint16_t d=0;
    a=a|(1<<31);
    a=a|(1<<30);
    a=a|(1<<15);
    a=a|(1<<16);
    a=a|(1<<17);
    a=a|(1<<18);
    a=a|(1<<19);
    printf("a=%d\n",a);
    d=(a&0x0000000f);
    printf("Message Id=%d\n",d);
    d=(a&0x000003f0);
    printf("Source Address=%d\n",d);
    d=(a&0x00007c00);
    printf("Destination Address=%d\n",d);
    d=(a&0x3ff80000);
    printf("Data Message=%d\n",d);
    return 0;
}