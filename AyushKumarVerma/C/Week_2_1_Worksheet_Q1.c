/* 1) Write a program, in which user is asked to choice from 0 to 2 for different tasks. . 
Choosing 0, will execute a function that would add 2 numbers. 
Choosing 1, will execute a function that would subtract 2 numbers, Choosing 2, 
will execute a function that would multiply 2 numbers.
In this program instead of use of switch case, use function pointers. */

#include <stdio.h>

void add(double num1, double num2) {
    printf("Adding %lf and %lf equals %lf", num1, num2, num1 + num2);
}

void subtract(double num1, double num2) {
    printf("Subtracting %lf and %lf equals %lf", num1, num2, num1 - num2);
}

void multiply(double num1, double num2) {
    printf("Multiplying %lf and %lf equals %lf", num1, num2, num1 * num2);
}

int main() {
    void (*ptr_to_fun[])(double, double) = {add, subtract, multiply};
    double num1, num2;
    int choice;
    printf("Enter Values of number 1 and number 2: ");
    scanf("%lf%lf", &num1, &num2);

    printf("\nEnter the choice - (0 - add | 1 - subtract | 2 - multiply) :");
    scanf("%d", &choice);

    if(choice > 2 || choice < 0) return 0;

    (*ptr_to_fun[choice])(num1, num2);

    return 0;
}