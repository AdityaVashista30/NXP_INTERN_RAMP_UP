#include<stdio.h>

struct batch{
	
	int roll;
	char name[20];
};

int main()
{
	struct batch a;
	struct batch (*ptr[1])={&a};
	
	scanf("%d", &ptr[0]->roll);
	scanf("%s", ptr[0]->name);
	
	printf("%d %s", ptr[0]->roll, ptr[0]->name);
	
	return 0;
}
