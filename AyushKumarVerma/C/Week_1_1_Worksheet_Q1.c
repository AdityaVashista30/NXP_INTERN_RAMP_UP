#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct myStructure {
    uint32_t age;
    char *name;
    bool isGraduated;
};

int main() {
    struct myStructure ayush;
    
    struct myStructure *ptrToStructure = &ayush;

    (*ptrToStructure).age = 25;
    (*ptrToStructure).name = "Ayush Kumar Verma";
    (*ptrToStructure).isGraduated = true;

    printf("The name of the student is : %s\n", (*ptrToStructure).name);
    printf("Age is: %X\n", (*ptrToStructure).age);
    printf("Is Graduated : %d\n",(*ptrToStructure).isGraduated);

    return EXIT_SUCCESS;
}