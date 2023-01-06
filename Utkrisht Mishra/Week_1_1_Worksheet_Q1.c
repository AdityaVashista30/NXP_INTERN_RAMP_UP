#include<stdio.h>
#include <stdbool.h>

struct utm_structure {

    int a;
    u_int16_t b;
    char c[100];
    bool d;

};

int main(){
    
    struct utm_structure utm_1;
    struct utm_structure *ptr;

    ptr = &utm_1;

    scanf("%d", &ptr -> a);
    scanf("%hu", &ptr -> b);
    scanf("%s", &ptr -> c);
    scanf("%d", &ptr -> d);

    printf("Values of UDT are 1. Integer : %d  \n, 2. Unsigned int short : %u \n, 3. String : %s \n, 4. Bool : %hu \n", ptr ->a, ptr ->b, ptr ->c, ptr ->d);

    return 0;

}