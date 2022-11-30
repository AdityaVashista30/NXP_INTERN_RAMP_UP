#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>

  void bin(unsigned int n)
  {
    //Decimal to Binary
    printf("\n\n\nBinary: \n");
    unsigned int i;
    int temp=0;
    for (i = 1 << 31; i > 0; i = i / 2)
    {
      temp+=1;
      if((n & i) != 0)
      {
      
        printf("1");
      }
      else
      {
       printf("0");
      }
      temp%5==0?printf("_"):printf("");
    }
      printf("\n\n\n");
  }
  void print_data(unsigned int msg_id,unsigned int src_add,unsigned int dest_add,unsigned int msg){
    printf("Message ID: %u\nSource Address: %u\nDestination Address: %u\nMessage : %u\n",msg_id,src_add,dest_add,msg);
  }
int main(){
  time_t times;
   srand((unsigned) time(&times));
  //Not taking the input but taking random numbers instead
    unsigned int a=0;
    unsigned int msg_id=rand()%16;
    unsigned int src_add=rand()%64;
    unsigned int dest_add=rand()%32;
    unsigned int t=(1<<11);
    unsigned int msg=rand()%t;


    printf("\nData before encoding: \n\n");
    print_data(msg_id,src_add,dest_add,msg);


    //Encoding

    a=msg_id<<28;                 //Bits 1-4: Message Id
    a=src_add<<22|a;              //Bits 5-10: Source Address
    a=dest_add<<17|a;             //Bits 11-15: Destination Address
    a=((1<<4)-1)<<13|a;           //reserved bit 16-19
    a=msg<<2|a;                   //Bits 20-30: Data/Message
    a=a|3;                        //reserved bit 31 AND 32 
    bin(a);
    printf("\n");

    //Decoding

    msg_id=src_add=dest_add=msg=5;
    msg_id=(((1<<4)-1)<<28&a)>>28;
    src_add=(((1<<6)-1)<<22&a)>>22;
    dest_add=(((1<<5)-1)<<17&a)>>17;
    msg=(((1<<11)-1)<<2&a)>>2;


    printf("\nData after encoding: \n\n");
    print_data(msg_id,src_add,dest_add,msg);
    return 0;
}
