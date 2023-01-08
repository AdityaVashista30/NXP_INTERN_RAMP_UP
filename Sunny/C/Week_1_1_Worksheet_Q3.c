#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct mystruct {
    uint32_t age;
    char *name;
    uint8_t num;
};

int main() {
    struct mystruct obj1;
    
    struct myStructure *ptr = &obj1;

    (*ptr).age = 25;
    (*ptr).name = "Sunny";
    (*ptr).num = 0b1010;

    printf("The name of the student is : %s\n", (*ptr).name);
    printf("Age is: %X\n", (*ptr).age);
    printf("Number : %d\n",(*ptr).num);

    return EXIT_SUCCESS;
}