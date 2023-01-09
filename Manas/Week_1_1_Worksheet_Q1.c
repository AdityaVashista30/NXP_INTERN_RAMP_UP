// 1. Make a user defined structure, which has 4 data values as follows:
//   a) data variable should occupy space of 4 bytes
//   b) data variable cant have range of value greater then 65535.
//   c) variable which can store string.
//   d) variable can only hold binary values.
  
//   Create the Object of this structure. The Object should be created via pointers
//   Initialise data values of structure using this object
//   and print those data values of structure using same object. Integer values should be printed in HEX format

#include <stdio.h>
#include <stdint.h>
#include<stdbool.h>

typedef struct 
{
    uint32_t var1;  // 4 bytes 
    char* var2;     // string
    uint16_t var3;  // value range not greater then 65536
    bool var4;   // hold binary values
}object;

int main() {
    // Write C code here
    
    object obj;
    object *ptr = &obj;
    
    ptr->var1 = 255;
    ptr->var2 = "Random String";
    ptr->var3 = 65535; 
    ptr->var4 = 0;
    
    printf("Var1 =  0x%x\n",ptr->var1); 
    printf("Var2 =  %s\n",ptr->var2);   
    printf("Var3 =  %d\n",ptr->var3);
    printf("Var4 =  %d\n",ptr->var4);
    
    return 0;
}