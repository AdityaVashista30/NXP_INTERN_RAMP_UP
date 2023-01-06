#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct myStructure {
    uint32_t age;
    char *name;
    uint8_t num;
};

int main() {
    struct myStructure ayush;
    
    struct myStructure *ptrToStructure = &ayush;

    (*ptrToStructure).age = 25;
    (*ptrToStructure).name = "Ayush Kumar Verma";
    (*ptrToStructure).num = 0b1010;

    printf("The name of the student is : %s\n", (*ptrToStructure).name);
    printf("Age is: %X\n", (*ptrToStructure).age);
    printf("Number : %d\n",(*ptrToStructure).num);

    return EXIT_SUCCESS;
}