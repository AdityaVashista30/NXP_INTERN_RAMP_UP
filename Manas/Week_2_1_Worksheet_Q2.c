// 2) Make a structure and initialise its data variables by creating the object of the structure via pointers. 
// Create a 1-D array of this structure of index 2. And then print the values of data variables of the structure.

#include<stdio.h>
#include<stdlib.h>

typedef struct obj
{
    int a;
    float b;
}obj;

int main()
{
    obj *object = malloc(2*sizeof(obj));
    object->a = 10;
    object->b = 10.5;

    (object+1)->a = 12;
    (object+1)->b = 12.5;

    printf("Object[0]->a: %d, Object[0]->b: %f\n", object->a,object->b);
    printf("Object[1]->a: %d, Object[1]->b: %f\n", (object+1)->a,(object+1)->b);

    return 0;
}