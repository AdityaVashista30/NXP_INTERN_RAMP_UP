#include<stdio.h>

struct utm_custom {
    int a;
    char b[10];
};

int main(){

    struct utm_custom o1, o2;
    struct utm_custom *ptr[2];
    ptr[0] = &o1;
    ptr[1] = &o2;

    // entering data
    for(int i=0; i<2; i++){
        scanf("%d", &ptr[i] -> a);
        scanf("%s", ptr[i] -> b);
    }

    // printing data

    printf("\n");
    for(int i=0; i<2; i++){
        printf("%d \n", ptr[i] -> a);
        printf("%s \n", ptr[i] -> b);
    }

    return 0;
}