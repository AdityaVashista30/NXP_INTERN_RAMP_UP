#include <stdio.h>
void add(int a, int b){
	printf("\nAddition : %d\n", a+b);
}
void sub(int a, int b){
	printf("\nSubtraction : %d\n", a-b);
}
void mul(int a, int b){
	printf("\nMultiplication : %d\n", a*b);
}

int main()
{
    printf("\n\n\n\n\n");
	void (*arr[])(int, int) = {add, sub, mul};
    int ch, a = 5, b = 3;
    // 1: add
    // 2: sub
    // 3: mul
    printf("Input: ");
	scanf("%d", &ch);
	(*arr[ch])(a, b);
	return 0;
}
