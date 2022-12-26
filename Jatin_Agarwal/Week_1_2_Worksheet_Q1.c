#include<stdio.h>

int main(){
    
unsigned int addr = 10000; //0b0010011100010000
unsigned char a = ((addr>>16) & (0xff)); 
 int x = (int)10000>> 16 ;
 printf("x= %d\n",x);
 int y= x & (0xff) ;
 printf("y= %d\n",y);
unsigned char b = (((addr>>8) & (0xff)));
int z = 10000>> 8 ;
printf("z= %d\n",z);
int w = z & (0xff) ;
printf("w= %d\n",w);
}
