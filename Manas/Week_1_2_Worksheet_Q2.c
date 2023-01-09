// 2) write a C program to create a 32 bit number with following user inputs:
// a) Bits 1-4: Message Id
// b) Bits 5-10: Source Address
// c) Bits 11-15: Destination Address
// d) Bits 20-30: Data/Message
// All reserved bits must be populated with 1.


#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// number = '|1.2.3.4| |.5.6.7.8.9.01| |.11.21.31.41.51| |.r.r.r.r| |.02.12.22.32.42.52.62.72.82.92,03| .r.r'

//             Msg Id,        Src,          Dest,           Res,        Data/Message,                   Res
void ToBinary(uint32_t n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            printf("%d",1);
        else
            printf("%d",0);
    }
    printf("\n");
}
uint32_t encode(uint32_t id, uint32_t src, uint32_t des, uint32_t data)
{
    uint32_t res = 0;

    res =  (id <<28);
    res |= (src <<22); 
    res |= (des <<17);
    res |= (((1<<4)-1)<<13);
    res |= (data<<2);
    res |= 3;
    return res; 
}

int main()
{
    uint32_t msg_id;
    uint32_t src_addr;
    uint32_t des_addr;
    uint32_t data;
    uint32_t code = 0;
    
    
    scanf("%u%u%u%u", &msg_id, &src_addr, &des_addr, &data);
    msg_id %= 16;
    src_addr %= 64;
    des_addr %= 32;
    data %= (1 << 11);

    code = encode(msg_id, src_addr, des_addr, data);

    printf("Message ID: ");
    ToBinary(msg_id);

    printf("Src Address: ");
    ToBinary(src_addr);

    printf("Des Address: ");
    ToBinary(des_addr);

    printf("Data: ");
    ToBinary(data);

    printf("Encoded Number : ");
    ToBinary(code);
}