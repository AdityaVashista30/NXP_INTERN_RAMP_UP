#include <stdio.h>
#include <stdlib.h>
typedef struct data {
    int value;
} data;
int main() {
    data obj, *ptr;
    ptr = &obj;
    ptr->value = 10;
    data *arr[3];
    printf("ptr=%d\n", ptr->value);
    for (int i = 0; i < 3; i++) {
        arr[i] = malloc(sizeof(data));
        arr[i]->value = i + 1;
    }
    for (int i = 0; i < 3; i++) {
        printf("[%d]=%d, ", i, arr[i]->value);
        free(arr[i]);
    }
    return 0;
}