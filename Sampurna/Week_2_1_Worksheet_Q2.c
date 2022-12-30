#include<stdio.h>
typedef struct data{
    int i;
    char name[15];
    char city[15];
    int pin;
}d;
int main()
{
    d d1,d2;
    d* arr[2];
    arr[0]=&d1;
    arr[1]=&d2;

    for(int i=0;i<2;i++)
    {
        printf("Enter Data:\n");
        scanf("%d",&arr[i]->i);
        scanf("%s",arr[i]->name);
        scanf("%s",arr[i]->city);
        scanf("%d",&arr[i]->pin);
    }
    printf("The data entered:\n");
    for(int i=0;i<2;i++)
    {
        printf("%d\n",arr[i]->i);
        printf("%s\n",arr[i]->name);
        printf("%s\n",arr[i]->city);
        printf("%d\n",arr[i]->pin);
        printf("\n");
    }
    return 0;
}