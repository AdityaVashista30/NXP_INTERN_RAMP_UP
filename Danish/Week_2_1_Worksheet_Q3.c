#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef union data {
    struct one {
        uint32_t key;      // 32 bits
        uint8_t key_type;  // FF
        bool isPrivate;    // 0/1
    } one;
    struct two {
        bool essential_core;  // 0/1
        uint8_t core_number;  // FF
    } two;
    struct three {
        uint16_t application_id;   // 16 bits
        uint8_t application_type;  // 4 bits
        uint8_t priority;          // 8 bits
    } three;

} data;
int main() {
    int cmd;
    printf("Command ");
    scanf("%d", &cmd);
    data d;
    if (cmd == 1) {
        scanf("%d", &d.one.key);
        scanf("%x", &d.one.key_type);
        scanf("%d", &d.one.isPrivate);
        printf("Key=%d, Type=%x, Private=%d\n", d.one.key, d.one.key_type, d.one.isPrivate);
    } else if (cmd == 2) {
        scanf("%d", &d.two.essential_core);
        scanf("%x", &d.two.core_number);
        printf("ECores=%d, CNo=%x\n", d.two.essential_core, d.two.core_number);
    } else if (cmd == 3) {
        scanf("%d", &d.three.application_id);
        scanf("%d", &d.three.application_type);
        scanf("%d", &d.three.priority);
        printf("AppId=%d, Type=%d, Priority=%d\n", d.three.application_id, d.three.application_type, d.three.priority);
    }
    printf("Object size: %d Bytes", sizeof(d));
    return 0;
}