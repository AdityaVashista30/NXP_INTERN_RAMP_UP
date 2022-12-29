#include <stdio.h>
#include <stdint.h>
struct dt{
    int a;
    char c;
};
int main()
{
    struct dt ob[2];
    struct dt *pt;
    pt=ob;
    pt->a=10;
    pt->c='S';
    printf("a=%d  ",pt->a);
    printf("c=%c",pt->c);
    pt++;
    pt->a=20;
    pt->c='T';
    printf("\na=%d  ",pt->a);
    printf("c=%c",pt->c);
    return 0;
}