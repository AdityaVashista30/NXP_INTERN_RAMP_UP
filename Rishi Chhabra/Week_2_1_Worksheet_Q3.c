//
//  main.c
//  Week_2_1_Worksheet_Q3.c
//
//  Created by Rishi  Chhabra on 07/01/23.
//

#include <stdio.h>
#include <stdbool.h>

struct command1 {
    uint32_t keyLength;
    uint8_t keyType;
    bool isPrivate;
};

struct command2 {
    bool essesntial_core;
    uint8_t core_number;
};

struct command3 {
    uint16_t application_id;
    int8_t application_type;
    int8_t priority;
};

union commands {
    struct command1 cmd1;
    struct command2 cmd2;
    struct command3 cmd3;
};

int main(int argc, const char * argv[]) {
    
    union commands rishi;
    int id;
    
    printf("Enter id");
    scanf("%d",&id);
    
    switch (id) {
        case 1:
            rishi.cmd1.keyLength = 1;
            rishi.cmd1.keyType = 2;
            rishi.cmd1.isPrivate = true;
            printf("keyLength = %d\nkeyType = %d\nisPrivate = %d",rishi.cmd1.keyLength,rishi.cmd1.keyType,rishi.cmd1.isPrivate);
            break;
        case 2:
            rishi.cmd2.core_number = 1;
            rishi.cmd2.essesntial_core = true;
            printf("core number = %d\nessentialcore = %d\n",rishi.cmd2.essesntial_core,rishi.cmd2.core_number);
            break;
        case 3:
            rishi.cmd3.application_id = 1;
            rishi.cmd3.application_type = 2;
            rishi.cmd3.priority = 1;
            printf("application id = %d\napplication type = %d\npriority = %d",rishi.cmd3.application_id,rishi.cmd3.application_type,rishi.cmd3.priority);
            break;
        default:
            break;
            
    }
    
    return 0;
}
