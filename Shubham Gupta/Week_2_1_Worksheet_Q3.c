// Create the most optimized struct, which takes in command id, source, and acts as service parser for 3 commands.
//     Command  Id 1: Get key info 
//         Components: key length (32 bit number), key type (hexadecimal value for 8 bits), isprivate (have binary value)
//     Command Id 2: Get Current Status
//         Components: essential_core (binary value), core number (8 bit hexadecimal number)
//     Command Id 3: Suspend Application 
//           Components: application id (16 bit number), application type (4 bit number), priority (8 bit value)
//     At a given time only one command can be executed and values of rest command components must be NULL.
//     Also for each command it is necessary to fill all details.

#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

struct cmd1{
    int key;
    uint8_t keyt;
    bool isprivate;
};

struct cmd2{
    bool essential_core;
    uint8_t corenum;
};

struct cmd3{
    uint16_t appid;
    uint8_t apptype;
    uint8_t priority;
};

union cmd{
    struct cmd1 var1;
    struct cmd2 var2;
    struct cmd3 var3;
};

int main(){
    union cmd var;
    int a;
    printf("Enter '1' to get key info, '2' for current status and '3' to suspend application\n ");
    scanf("%d",&a);
    if(a==1){
        printf("Enter key length (32 bit number), key type (hexadecimal value for 8 bits)and isprivate (have binary value) respectivey\n");
        scanf("%d %hhx %d",&var.var1.key,&var.var1.keyt,&var.var1.isprivate);
        printf("Key length=%d\nkey type=%x\nisprivate=%d\n",var.var1.key,var.var1.keyt,var.var1.isprivate);
    }
    else if(a==2){
        printf("Enter essential_core (binary value) and core number (8 bit hexadecimal number) respectively.\n");
        scanf("%d %hhx",&var.var2.essential_core,&var.var2.corenum);
        printf("Essential core=%d\nCore number=%x\n",var.var2.essential_core,var.var2.corenum);
    }
    else if(a==3){
        printf("Enter application id (16 bit number), application type (4 bit number) and priority (8 bit value) respectively\n");
        scanf("%hd %hhd %hhd",&var.var3.appid,&var.var3.apptype,&var.var3.priority);
        printf("application id=%d\napplication type=%d\npriority=%d\n",var.var3.appid,var.var3.apptype,var.var3.priority);
    }
    else{
        printf("Invalid input!! Exiting program...\n");
    }
}