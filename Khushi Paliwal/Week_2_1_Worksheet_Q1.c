#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<stdlib.h>

int add(int a,int b)
{
	return (a+b);
}

int sub(int a,int b)
{
	return (a-b);
}

int mul(int a,int b)
{
	return (a*b);
}

int main()
{
	int (*ptr[])(int, int)={add, sub, mul};
	
	int a, b, c;
	
	printf("Enter number 1: ");
	scanf("%d", &a);
	
	printf("Enter number 2: ");
	scanf("%d", &b);
	
	printf("Enter choice: \n1.add \n2.sub \n3.mul\n");
	scanf("%d", &c);
	
	c=c-1;
	
	int res;
	res=ptr[c](a,b);
	
	printf("Result is: %d",res);
	
	return 0;
}
