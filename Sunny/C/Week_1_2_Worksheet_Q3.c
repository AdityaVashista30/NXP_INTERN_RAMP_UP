#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void printNumber(uint32_t msgID, uint32_t src, uint32_t des, uint32_t data)
{
    printf("Message ID: %u\nSource Address: %u\nDestination Address: %u\nData: %u\n", msgID, src, des, data);
}

uint32_t createNumber(uint32_t msg_id, uint32_t src_addr, uint32_t des_addr, uint32_t data)
{
    // 0b 1_2_3_4 . 5_6_7_8_9_10 . 11_12_13_14_15 . r_r_r_r . 20_21_22_23_24_25_26_27_28_29_30 . r_r
    uint32_t final_number = 0;
    final_number = (msg_id << 28);
    final_number = (src_addr << 22) | final_number;
    final_number = (des_addr << 17) | final_number;
    final_number = ((15) << 13) | final_number;
    final_number = (data << 2) | final_number;
    final_number = final_number | 3;

    return final_number;
}

void decodeNumber(uint32_t final_number) {
    uint32_t msg_id, src_addr, des_addr, data;
    msg_id = ((((15) << 28) & final_number) >> 28);
    src_addr = ((((63) << 22) & final_number) >> 22);
    des_addr = (((31 << 17) & final_number) >> 17);
    data = (((2047) << 2) & final_number) >> 2;

    printNumber(msg_id, src_addr, des_addr, data);
}


int main()
{
    uint32_t msg_id;
    uint32_t src_addr;
    uint32_t des_addr;
    uint32_t data;
    uint32_t final_number = 0;
    // taking input from user
    scanf("%u%u%u%u", &msg_id, &src_addr, &des_addr, &data);

    // 15 is 1111,63 is 111111 31 is 11111 2047 is 11 1s
    msg_id &= 15;
    src_addr &= 63;
    des_addr &= 31;
    data &= 2047;

    final_number = createNumber(msg_id, src_addr, des_addr, data);

    printf("Final Number : %u\n", final_number);

    printNumber(msg_id, src_addr, des_addr, data);

    decodeNumber(final_number);

    return 0;
}