#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int mul(int a,int b){
    return a*b;
}
int main(){
int (*ptr[3]) (int,int);
//pointer to a function of lenght 3
printf(" enter a choice from 0 to 2 and two numbers of choice\n");
int ch,a,b;
scanf("%d %d %d",&ch,&a,&b);
if(ch<0||ch>2)return 0;
ptr[0]=add;
ptr[1]=sub;
ptr[2]=mul;
printf(" the result is %d",ptr[ch](a,b));
return 0;
}