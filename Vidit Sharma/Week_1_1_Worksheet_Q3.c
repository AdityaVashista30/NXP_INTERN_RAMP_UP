#include<stdio.h>
#include<stdbool.h>
struct user_def{
   int a;
   char str[50];
   short b;
   bool flag;
};
int main(){
    struct user_def *ptr,obj;
    ptr=&obj;
    scanf("%d",&ptr->a);
    scanf("%s",ptr->str);
    scanf("%hu",&ptr->b);
    int temp;
    scanf("%d",&temp);
    ptr->flag=temp;
    printf("The values of user defined data structure are %X %s %hu %d",ptr->a,ptr->str,ptr->b,ptr->flag);
    return 0;
}