//
//  main.c
//  Week_2_1_Worksheet_Q1.c
//
//  Created by Rishi  Chhabra on 07/01/23.
//

#include <stdio.h>

void add(int a,int b) {
    printf("Addition %d + %d = %d\n",a,b,a+b);
}

void sub(int a,int b) {
    printf("Subtraction %d - %d = %d\n",a,b,a-b);
}

void mul(int a,int b) {
    printf("Multiplication %d x %d = %d\n",a,b,a*b);
}

int main(int argc, const char * argv[]) {
    
    void (*function_array_ptr[])(int,int) = {add,sub,mul};
    
    int n,a,b;
    printf("Enter 0 for Addition, 1 for Subtraction, 2 for Multiplication\n");
    scanf("%d",&n);
    printf("\nEnter a\n");
    scanf("%d",&a);
    printf("\nEnter a\n");
    scanf("%d",&b);
    printf("%d %d %d\n",n,a,b);
    
    (*function_array_ptr[n]) (a,b);
    
    return 0;
}
