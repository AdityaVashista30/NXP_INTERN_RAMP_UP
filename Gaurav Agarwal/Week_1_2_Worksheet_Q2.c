
#include <stdlib.h>
#include <stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>
char* toBinary(uint32_t number, int len)
{
    char* binary = (char*)malloc(sizeof(char) * len);
    int k = 0;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary[k++] = (number & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}
int main ()
{
    int len = 32;
  uint32_t number=0;
  uint32_t id;
  uint32_t sa;
  uint32_t da;
  uint32_t msg;
  scanf("%u",&id);
   scanf("%u",&sa);
    scanf("%u",&da);
     scanf("%u",&msg);
number=number|(id<<28);
number=number|(sa<<22);
number=number|(da<<17);
number=number|(msg<<2);
number=number|(15<<13);
number=number|3;
printf("%u",number);
char* binary = toBinary(number, len);
printf("\n The binary representation of is %s \n",binary);
char id1[5];
char sa1[6];
char da1[5];
char msg1[11];
id1[0]=binary[0];
id1[1]=binary[1];
id1[2]=binary[2];
id1[3]=binary[3];
id1[4]=binary[4];
sa1[0]=binary[5];
sa1[1]=binary[6];
sa1[2]=binary[7];
sa1[3]=binary[8];
sa1[4]=binary[9];
sa1[5]=binary[10];
da1[0]=binary[11];
da1[1]=binary[12];
da1[2]=binary[13];
da1[3]=binary[14];
da1[4]=binary[15];
msg1[0]=binary[20];
msg1[1]=binary[21];
msg1[2]=binary[22];
msg1[3]=binary[23];
msg1[4]=binary[24];
msg1[5]=binary[25];
msg1[6]=binary[26];
msg1[7]=binary[27];
msg1[8]=binary[28];
msg1[9]=binary[29];
msg1[10]=binary[30];
printf("%s \n",id1);
printf("%s \n",sa1);
printf("%s \n",da1);
printf("%s",msg1);
free(binary);
  return 0;
}
