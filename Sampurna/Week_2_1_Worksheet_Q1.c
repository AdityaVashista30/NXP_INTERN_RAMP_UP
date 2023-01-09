#include<stdio.h>
int add(int num1,int num2)
{
    int ans = num1+num2;
    return ans;
}
int sub(int num1,int num2)
{
    int ans = num1-num2;
    return ans;
}
int mul(int num1,int num2)
{
    int ans = num1*num2;
    return ans;
}
int main()
{
    int num1,num2,result,choice;
    printf("Enter 1st Number:");
    scanf("%d",&num1);
    printf("Enter 2nd Number:");
    scanf("%d",&num2);
    printf("Enter 0 to add \nEnter 1 to subtract \nEnter 2 to multiply\nChoice:");
    scanf("%d",&choice);
    if (choice<0|| choice>2)
    return 0;
    //function pointer array declaration
    int (*fp[3]) (int,int);
    
    fp[0]=add;
    fp[1]=sub;
    fp[2]=mul;

    result = (*fp[choice])(num1,num2);
    printf("Result: %d",result);
    return 0;
}