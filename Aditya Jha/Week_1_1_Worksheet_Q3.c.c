#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct nxp{
bool c;
unsigned int a;
char b[50];
 };

int main(){
    struct nxp* obj;
    obj->c=true;
    obj->a=5;
    strcpy(obj->b,"nxp semiconductors");
    printf("This is the unsigned integer: 0x%X\n",obj->a);
    printf("This is the string: %s\n",obj->b);
    printf("This is the boolean: %s\n",obj->c?"true":"false");
    
    return 0;
}