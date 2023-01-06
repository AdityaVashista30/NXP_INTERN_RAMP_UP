#include<stdio.h>

int add(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
int mul(int a, int b){
    return a*b;
}

int main() {

    int opt, a, b;
    int (*fun_ptr[3])(int,int) = {add, sub, mul};
    printf("Enter 1st number: ");
    scanf("%d", &a);
    printf("\n Enter 2nd number: ");
    scanf("%d", &b);
    printf("Enter function choice: ");
    scanf("%d", &opt);
    int output = (*fun_ptr[opt])(a,b);
    printf("Final answer is: %d \n", output);

    return 0;
}