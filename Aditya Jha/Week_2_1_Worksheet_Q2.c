#include<stdio.h>
#include<stdlib.h>
struct t{
        int a;
        char b;
    };
int main(){
    struct t *ptr=(struct t*)malloc(2*sizeof(struct t));
    (ptr)->a=5;
    ptr->b='a';
    (ptr+1)->a=1;
    (ptr+1)->b='b';
    printf("Value 1: %d\nValue 2: %c\n",ptr->a,ptr->b);
    printf("Value 1: %d\nValue 2: %c",(ptr+1)->a,(ptr+1)->b);


    return 0;
}