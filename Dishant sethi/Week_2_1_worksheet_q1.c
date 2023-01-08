#include <stdio.h>
 void ad(int a,int b){
     printf("Addition=%d",a+b);
 }
 void mul(int a,int b){
     printf("Multiplication=%d",a*b);
 }
 void sub(int a,int b){
     printf("Subtraction=%d",a-b);
 }
 int main()
 {
     int a=10,b=5,c;
     void (*fnptr[])(int,int)={ad,sub,mul};
     printf("Enter 0 for Addition, 1 for Subtraction and 2 for Multiplication\n");
     scanf("%d",&c);
     (fnptr[c])(a,b);
 }