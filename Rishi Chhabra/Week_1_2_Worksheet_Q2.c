//
//  main.c
//  Week_1_2_Worksheet_Q2.c
//
//  Created by Rishi  Chhabra on 07/01/23.
//

#include <stdio.h>
#include<math.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int a = rand();
    printf("%d, %d",a%16,(a%16)<<28);
    return 0;
}
