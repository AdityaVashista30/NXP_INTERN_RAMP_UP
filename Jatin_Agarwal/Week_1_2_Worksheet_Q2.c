#include<stdio.h>
#include<string.h>

void main(){

    char msgId[33],sa[7],da[6],data[12];
    printf("Enter 4 bits for message id");
    gets(msgId); //enter message id
    printf("Enter 6 bits for source address");
    gets(sa); //enter addr
    printf("Enter 5 bits for destination address");
    gets(da); //enter address
    printf("Enter 11 bits of data");
    gets(data); //enter message

    //concat strings
    strcat(msgId,sa);
    strcat(msgId,da);
    strcat(msgId,"1111");
    strcat(msgId,data);
    strcat(msgId,"11");
    printf("Packet is %s",msgId);
    
}