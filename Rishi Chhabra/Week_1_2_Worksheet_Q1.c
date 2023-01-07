//
//  Week_1_2_Worksheet_Q1.c
//  Week_1_1_Worksheet_Q1.c
//
//  Created by Rishi  Chhabra on 07/01/23.
//

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int main() {
        
    uint16_t addr = 10000;


    uint8_t x = addr >> 16;
    uint8_t y = ((addr>>16) & (0xff));

    uint8_t z = addr >> 8;
    uint8_t w = (((addr>>8) & (0xff)));


    printf("x = %ld\ny = %ld\nz = %ld\nw = %ld\n",x,y,z,w);

}
