#include<stdio.h>
#include<stdbool.h> //header file for boolean
#include<string.h>
struct  StudentData{
    unsigned short int number;
    char *str;
    bool f;
};

int main(){
    struct StudentData st;// creating object of the structure
    struct StudentData* ptr=&st; //pointer of this structure type on this object
    ptr->number=7;
    ptr->str="Yug";
    ptr->f=1;
    printf("Number=%hu\n",ptr->number);
    printf("String=%s\n",ptr->str);
    printf("Binary=%d\n",ptr->f);

}