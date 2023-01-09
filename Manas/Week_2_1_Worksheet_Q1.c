// 1) Write a program, in which user is asked to choice from 0 to 2 for different tasks. . 
// Choosing 0, will execute a function that would add 2 numbers. Choosing 1, will execute a function 
// that would subtract 2 numbers, Choosing 2, will execute a function that would multiply 2 numbers.
// In this program instead os use of switch case, use function pointers.


#include<stdio.h>


void (*calc[3])(int,int);

void add(int x, int y)
{
    printf("%d\n",x+y);
}

void sub(int x, int y)
{
    printf("%d\n",x-y);
}

void mul(int x,int y)
{
    printf("%d\n",x*y);
}

int main()
{
    
    int choice, num1,num2;
    do
    {
        printf("0. Addition.\n");
        printf("1. Subtraction.\n");
        printf("2. Multiplication.\n");
        printf("3.Exit.\n");
        printf("Enter Choice: \n");
        scanf("%d",&choice);
        if (choice==3)
            return 0;
            
        printf("Enter num1 followd by num2 ");
        scanf("%d %d",&num1,&num2);

        printf("Result: ");
        calc[0]=&add;
        calc[1]=&sub;
        calc[2]=&mul;

        (*calc[choice])(num1,num2);
    }while( choice>=0 && choice<=2);

    return 0;
}