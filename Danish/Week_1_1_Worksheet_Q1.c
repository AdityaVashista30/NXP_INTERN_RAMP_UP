#include <stdio.h>
#include <stdlib.h>

struct Week_1_1_Worksheet_Q1 {
    unsigned int val;
    char str[4];
    int binary;
};
void print(struct Week_1_1_Worksheet_Q1 *q1) {
    printf("Integer: %X\n", q1->val);
    printf("String: %s\n", q1->str);
    printf("Binary: %d\n", q1->binary);
    printf("Size of Object: %d Bytes\n", sizeof(*q1));
}
void scan(struct Week_1_1_Worksheet_Q1 *q1) {
    q1->val = 15;
    q1->str[0] = 'A';
    q1->str[1] = 'B';
    q1->str[2] = 'C';
    q1->binary = 0b11001;
}
int main() {
    struct Week_1_1_Worksheet_Q1 *q1;
    q1 = malloc(sizeof(struct Week_1_1_Worksheet_Q1));
    scan(q1);
    print(q1);
    free(q1);
    return 0;
}
