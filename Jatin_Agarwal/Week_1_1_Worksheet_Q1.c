#include<stdio.h>
#include<stdbool.h>

//structure
struct myStruct{
       unsigned int var1; //variable to store values less than 65535
       char *str; //pointer variable to store string values
       bool var2; //variable to store boolean values
    };

int main(){

    struct myStruct *obj = (struct myStruct*)malloc(sizeof(struct myStruct)); //create object
    
    //initialise
    obj->var1 = 12;
    obj->str = "Loyal";
    obj->var2 = true;
    
    //print
    printf("Integer value in HEX is %x\n",obj->var1);
    printf("String is %s\n",obj->str);
    printf("Boolean is %d\n",obj->var2);
}