#include<stdio.h>
#include<stdlib.h>

//structure
struct myStruct{
        int var1; //variable to store int
       char ch; //pointer variable to store char values
       
    };

int main(){

    struct myStruct *obj = (struct myStruct*)malloc(sizeof(struct myStruct)); //create object
    
    //initialise
    obj->var1 = 12;
    obj->ch = 'k';
    
    //create array of struct
    struct myStruct structarr[2];
    structarr[0]= *obj;
    
    //print
    struct myStruct structarr[2];
    
    printf("int= %d\n",structarr[0].var1);
    printf("char= %c\n",structarr[0].ch);

    return 0;
}