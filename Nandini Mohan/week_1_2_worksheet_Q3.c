#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t create(uint32_t msg_id, uint32_t src_addr, uint32_t des_addr, uint32_t data)
{
    uint32_t address = 0;
    address = (msg_id << 28);
    address = (src_addr << 22) | address;
    address = (des_addr << 17) | address;
    address = (((1 << 4) - 1) << 13) | address;
    address = (data << 2) | address;
    address = address| 3;

    return address;
}

void print(uint32_t msgID, uint32_t src, uint32_t des, uint32_t data)
{
    printf("Message ID: %u\nSource Address: %u\nDestination Address: %u\nData: %u\n", msgID, src, des, data);
}
void decode(uint32_t address){
    uint32_t msg_id, src_addr, des_addr, data;
    msg_id = (((((1 << 4) - 1) << 28) & address)>> 28);
    src_addr = (((((1 << 6) - 1) << 22) & address)>> 22); 
    des_addr = (((((1 << 5) - 1) << 17) & address)>> 17);
    data = ((((1 << 11) - 1) << 2) & address)>> 2;

    print(msg_id, src_addr, des_addr, data); 
}

int main()
{
    uint32_t msg_id;
    uint32_t src_addr;
    uint32_t des_addr;
    uint32_t data;
    uint32_t address= 0;
    scanf("%u%u%u%u", &msg_id, &src_addr, &des_addr, &data);
    msg_id %= 16;
    src_addr %= 64;
    des_addr %= 32;
    data %= (1 << 11);

    address= create(msg_id, src_addr, des_addr, data);

    printf("address : %u\n", address);

    print(msg_id, src_addr, des_addr, data);

    decode(address);

    return 0;
}