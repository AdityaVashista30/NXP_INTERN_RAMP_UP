#include <stdio.h>
void fun1(int a,int b){
    printf("%d",a+b);
}
void fun2(int a,int b){
    printf("%d",a-b);
}
void fun3(int a,int b){
    printf("%d",a*b);
}
int main()
{
    int a=5,b=2;
    void (*fp)(int,int);
    int choice;
    scanf("%d",&choice);
    if(choice==0){
        fp=fun1;
        (*fp)(a,b);
    }
    if(choice==1){
        fp=fun2;
        (*fp)(a,b);
    }
    if(choice==2){
        fp=fun3;
        (*fp)(a,b);
    }
    
}