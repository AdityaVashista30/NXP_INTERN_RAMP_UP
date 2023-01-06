#include <stdio.h>
#include <stdint.h>
struct data{
    int a;
    char b;
};
int main()
{
    struct data obj[2];
    struct data *pt;
    pt=&obj;
    pt->a=5;
    pt->b='N';
    printf("a=%d  ",pt->a);
    printf("b=%c",pt->b);
    pt++;
    pt->a=10;
    pt->b='M';
    printf("\na=%d  ",pt->a);
    printf("b=%c",pt->b);
    return 0;
}
