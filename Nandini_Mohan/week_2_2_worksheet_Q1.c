#include<stdio.h>
#include<stdlib.h>

struct c{
	char section;
	int c;
        int total
	struct data *obj;
};
struct data{
	int rollno;
	int marks[5];
};

int main()
{
	struct c classes[10];

	for(int i=0; i<10; i++)
	{
		if('A'+i=='A' || 'A'+i=='E' || 'A'+i=='I')
		{
			classes[i].total=25;
		}
		else if('A'+i-1=='A' || 'A'+i-1=='E' || 'A'+i-1=='I')
		{
			classes[i].total=20;
		}
		else if('A'+i+1=='A' || 'A'+i+1=='E' || 'A'+i+1=='I')
		{
			classes[i].total=22;
		}
		else
		{
			classes[i].total=30;
		}

		classes[i].sec='A'+i;
		classes[i].count=0;
//		struct data st[classes[i].total];
//		classes[i].obj=st;
		classes[i].obj=(struct data*) malloc(classes[i].total*sizeof(struct data));
	}

	int a;

	while(1)
	{
		printf("\nEnter your query: \n 1)Enter marks of student \n 2)Display marks of student \n 3)Exit \n");
		scanf("%d", &a);

		char s;
		int r;

		switch(a)
		{
			case 1:
				printf("Enter section:");
				scanf(" %c",&s);

				if(s<'A' && s>'J')
				{
					printf("Invalid section. \n");
				}
				else if(classes[(int)(s)-65].total==classes[(int)(s)-65].count)
				{
					printf("Class is full. \n");
				}
				else
				{
					printf("Enter rollno:");
					scanf("%d",&r);

					if(classes[(int)(s)-65].total>=r)
					{
						printf("Enter marks: \n");

						for(int i=0; i<5; i++)
						{
							int marks=0;
							scanf("%d", &marks);
							classes[(int)(s)-65].obj[r-1].marks[i]=marks;
						}
					}
				}
				classes[(int)(s)-65].count++;
				break;

			case 2:
				printf("Enter section:");
				scanf(" %c", &s);
				printf("Enter rollnumber:");
				scanf("%d", &r);

				if(s<'A' && s>'J')
				{
					printf("Wrong section \n");
				}
				else if(classes[(int)(s)-65].count==0)
				{
					printf("No data available.");
				}
				else if(r<=classes[(int)(s)-65].total && r<=classes[(int)(s)-65].count)
				{
					printf("Marks are ");
					for(int i=0; i<5; i++)
					{
						printf("%d ", classes[(int)(s)-65].obj[r-1].marks[i]);
					}
				}
				else
				{
					printf("No information available or invalid roll number. \n");
				}
				break;

			case 3:
				break;
		}
	}

}