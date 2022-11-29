#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main(){
    //  a) Bits 1-4: Message Id
    // b) Bits 5-10: Source Address
    // c) Bits 11-15: Destination Address
    // d) Bits 20-30: Data/Message
    // All reserved bits must be populated with 1.
    int arr[32];
    for(int i=0;i<32;i++)arr[i]=1;

    printf(" enter the 4 message bits in binary \n");
    for(int i=1;i<=4;i++){
        scanf("%d",&arr[i]);
    }
      printf(" enter the 6 Source Address bits in binary \n");
    for(int i=5;i<=10;i++){
        scanf("%d",&arr[i]);
    }
      printf(" enter the 5 Destination Address bits in binary \n");
    for(int i=11;i<=15;i++){
        scanf("%d",&arr[i]);
    }
      printf(" enter the 11 Data/Message bits in binary \n");
    for(int i=20;i<=30;i++){
        scanf("%d",&arr[i]);
    }
    printf(" the 32 bit number is  ");
    for(int i=0;i<32;i++){
        printf("%d ",arr[i]);
    }
}