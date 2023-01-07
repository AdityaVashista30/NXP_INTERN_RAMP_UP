#include<stdio.h>
#include<string.h>

char* substring(const char *s, char *d, int strt, int len)
{
    while (len > 0)
    {
        *d = *(s + strt);
 
        d++;
        s++;
        len--;
    }
 
    *d = '\0';
    return d;
}

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

    //extract
    char xmsgid[4] = substring(msgId,xmsgid, 0,4);
    printf("msgid = %s",xmsgid);
    char xsa[6] = substring(xmsgid,xsa,4,6);
    printf("source addr = %s",xsa);
    char xda[5] = substring(msgId,xda, 10,15);
    printf("dest addr = %s",xda);
    char xdata[11] = substring(msgId,xdata, 19,30); 
    printf("Data is = %s",xdata);
    
}