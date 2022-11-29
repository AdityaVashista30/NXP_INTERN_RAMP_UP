#include<stdio.h>
#include<stdint.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int arr[32];
    for(int i=0;i<32;i++)arr[i]=1;

    printf(" enter the 4 message id bits in binary \n");
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
    int message,message_id,src_addr,dest_addr;
    int temp=0;
    for(int i=1;i<=4;i++){
          temp+=pow(2,i);
    }
    message_id=temp;
    temp=0;
    for(int i=5;i<=10;i++){
          temp+=pow(2,i);
    }
    src_addr=temp;
    temp=0;
    for(int i=11;i<=15;i++){
          temp+=pow(2,i);
    }
    dest_addr=temp;
    temp=0;
    for(int i=20;i<=30;i++){
          temp+=pow(2,i);
    }
    message=temp;
    printf(" \nMessage_id:%d \nSource address:%d\nDestination address:%d\nMessage:%d ",message_id,src_addr,dest_addr,message);
   return 0;
}