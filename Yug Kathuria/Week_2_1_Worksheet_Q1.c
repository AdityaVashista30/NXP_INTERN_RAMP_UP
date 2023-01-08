//This program demostrates how we can use function pointer and switch between mltiple function without switch case

#include <stdio.h>

void addition(int a,int b) {
    printf("Addition %d + %d = %d\n",a,b,a+b);
}

void subtract(int a,int b) {
    printf("Subtraction %d - %d = %d\n",a,b,a-b);
}

void multiply(int a,int b) {
    printf("Multiplication %d x %d = %d\n",a,b,a*b);
}

int main(int argc, const char * argv[]) {
    
    void (*function_array_ptr[])(int,int) = {addition,subtract,multiply};
    
    int n,a,b;
    printf("Enter 0 for Addition, 1 for Subtraction, 2 for Multiplication\n");
    scanf("%d",&n);
    printf("\nEnter a\n");
    scanf("%d",&a);
    printf("\nEnter b\n");
    scanf("%d",&b);
        
    (*function_array_ptr[n]) (a,b);
    
    return 0;
}