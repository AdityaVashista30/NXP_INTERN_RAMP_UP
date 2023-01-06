#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiply(int a,int b)
{
    return a*b;
}
int main() {
    int choice, a, b, (*fun)(int, int);
    scanf("%d%d%d", &choice, &a, &b);
    if (choice == 0) {
        fun = add;
    } else if (choice == 1) {
        fun = subtract;
    } else if (choice == 2) {
        fun = multiply;
    } else {
        printf("Enter Correct Choice.");
        return 0;
    }
    printf("Ans: %d", (*fun)(a, b));
    return 0;
}
