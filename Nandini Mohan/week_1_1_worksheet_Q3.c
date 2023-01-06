#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct s{
	float a;
	unsigned int b;
	char c[50];
	bool d;
 };

int main()
{
	struct s obj;
	struct s* ptr;
	ptr=&obj;

	scanf("%f", &ptr->a);
	scanf("%u", &ptr->b);
	scanf("%s", &ptr->c);
	scanf("%d", &ptr->d);
        printf("The user defined data structures are as follows : \n 1. Float %f \n 2. Unisigned int %u \n 3. String %s \n 4. Boolean %d", ptr->a, ptr->b, ptr->c, ptr->d);

	return 0;

}