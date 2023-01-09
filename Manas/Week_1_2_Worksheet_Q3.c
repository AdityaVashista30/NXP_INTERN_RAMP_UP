// 3) Write a C program to decode the message unit created in Q.2. to decode message,
// message id, source address and destination address.

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

void decode(uint32_t code)
{
    uint32_t msg_id, src_addr, des_addr, data;
    msg_id = (((((1 << 4) - 1) << 28) & code) >> 28);
    src_addr = (((((1 << 6) - 1) << 22) & code) >> 22); 
    des_addr = (((((1 << 5) - 1) << 17) & code) >> 17);
    data = ((((1 << 11) - 1) << 2) & code) >> 2;

    printf("Message ID: ");
    ToBinary(msg_id);

    printf("Src Address: ");
    ToBinary(src_addr);

    printf("Des Address: ");
    ToBinary(des_addr);

    printf("Data: ");
    ToBinary(data);

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
    
    printf("Encoded Number : ");
    ToBinary(code);

    printf("Decoded Values: \n");
    decode(code);
}