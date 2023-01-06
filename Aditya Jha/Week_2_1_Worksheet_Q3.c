#include<stdio.h>
#include<stdbool.h>
#include <stdint.h>
#include<stdlib.h>

struct cmd_1{
    unsigned int key_len;
   unsigned char key_type;
     bool is_private;
};
struct cmd_2{
bool essential_core;
uint8_t a;
};
struct cmd_3{
uint16_t application_id;
int8_t application_type;
int8_t priority;
};
union commands{
    struct cmd_1 a;
    struct cmd_2 b;
    struct cmd_3 c;
};
void print(union commands ser_par){
printf("\nCMD_1: \n");
printf("%d  %c  %d",ser_par.a.is_private,ser_par.a.key_len,ser_par.a.key_type);
printf("\nCMD_2: \n");
printf("%u  %d",ser_par.b.a,ser_par.b.essential_core);
printf("\nCMD_3: \n");
printf("%lu %u  %u",ser_par.c.application_id,ser_par.c.application_type,ser_par.c.priority);
}
int main(){
    int command_id;
    union commands ser_par;


    printf("\nCommand ID: \n");
    scanf("%d",&command_id);
    switch (command_id)
    {
    case 1:
        ser_par.a.key_len=1;
        ser_par.a.is_private=true;
        ser_par.a.key_type='a';
        print(ser_par);
        break;
    case 2:
        ser_par.b.a=255;
        ser_par.b.essential_core=true;
        print(ser_par);
        break;
    case 3:
        ser_par.c.application_id=1;
        ser_par.c.application_type=1;
        ser_par.c.priority=1;
        print(ser_par);
        break;
    default:
        break;
    }
    return 0;
}