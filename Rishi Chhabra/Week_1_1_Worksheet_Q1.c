//
//  main.c
//  Week_1_1_Worksheet_Q1.c
//
//  Created by Rishi  Chhabra on 20/11/22.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct rishi_NXP {
    unsigned short int number;
    bool binary;
    char *str;
};

int main() {
    struct rishi_NXP rishi;
    struct rishi_NXP* rishi_ptr = &rishi;
    
    (*rishi_ptr).number = 8;
    (*rishi_ptr).str = "rishi";
    (*rishi_ptr).binary = 1;
    
    printf("Number = %hu\n",(*rishi_ptr).number);
    printf("Name = %s\n",(*rishi_ptr).str);
    printf("Binary = %d\n",(*rishi_ptr).binary);
    return 0;
}
