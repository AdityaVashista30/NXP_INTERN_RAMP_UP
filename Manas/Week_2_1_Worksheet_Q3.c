// 3) Create the most optimized struct, which takes in command id, source, and acts as service parser for 3 commands.
//     Command  Id 1: Get key info 
//         Components: key length (32 bit number), key type (hexadecimal value for 8 bits), isprivate (have binary value)
//     Command Id 2: Get Current Status
//         Components: essential_core (binary value), core number (8 bit hexadecimal number)
//     Command Id 3: Suspend Application 
//           Components: application id (16 bit number), application type (4 bit number), priority (8 bit value)
//     At a given time only one command can be executed and values of rest command components must be NULL.
//     Also for each command it is necessary to fill all details.

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

typedef struct cmd_1
{
    uint32_t key_len;
    uint8_t key_type;
    bool is_private;
}cmd_1;

typedef struct cmd_2
{
    bool core;
    uint8_t core_num;
}cmd_2;

typedef struct cmd_3
{
    uint16_t app_id;
    uint8_t app_type;
    uint8_t priority;
}cmd_3;

typedef union cmd
{
    cmd_1 key_info;
    cmd_2 get_curr_status;
    cmd_3 suspend_application;
}cmd;

void display(cmd command)
{
    printf("Key Info Values: \n");
    printf("key len:%u\t key type: 0x%x\t is_private: %d\n\n",command.key_info.key_len,
            command.key_info.key_type,command.key_info.is_private);
   
    printf("Get Curr Status: \n");
    printf("core: %u\t core_num: 0x%x\n\n",command.get_curr_status.core,
            command.get_curr_status.core_num);
    
    printf("Suspend Application:\n");
    
    printf("app id: %hu\t app_type: %u\t priority: %u\n",command.suspend_application.app_id,
            command.suspend_application.app_type,command.suspend_application.priority);
}
int main(void)
{
    int id;
    cmd command;
    
    printf("Give command id b/w 1 and 3: ");
    scanf("%d",&id);

    switch(id)
    {
        case 1:
            command.key_info.key_len=5;
            command.key_info.key_type=0xFF;
            command.key_info.is_private=true;
            display(command);
            break;
        
        case 2:
            command.get_curr_status.core=false;
            command.get_curr_status.core_num=50;
            display(command);
            break;
        
        case 3:
            command.suspend_application.app_id = 10101;
            command.suspend_application.app_type=13;
            command.suspend_application.priority=98;
            display(command);
            break;
        default:
            printf("Invalid Input. Exit in Process..... ");
            break;
    }
    return 0;
}