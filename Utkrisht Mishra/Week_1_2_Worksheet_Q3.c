#include<stdio.h>


int main(){

    // using array

    int arr[32];
    for(int i=1; i<=32; i++){
        arr[i] = 1;
    }
    //creating number
    // message id
    printf("Now enter the message id: ");
    for (int i=1; i<=4; i++){
        scanf("%d", &arr[i]);
    }
    // src addr
    printf("Now enter the source address: ");
    for (int i=5; i<=10; i++){
        scanf("%d", &arr[i]);
    }
    // dest addr
    printf("Now enter the destination address: ");
    for (int i=11; i<=15; i++){
        scanf("%d", &arr[i]);
    }
    // msg
    printf("Now enter the message: ");
    for (int i=20; i<=30; i++){
        scanf("%d", &arr[i]);
    }

    //printing number
    for (int i=1; i<=32; i++){
        printf("%d", arr[i]);
    }

    // decoding message

    printf("\n the message id is: ");
    for (int i=1; i<=4; i++){
        printf("%d", arr[i]);
    }
    // src addr
    printf("\n the source address is: ");
    for (int i=5; i<=10; i++){
        printf("%d", arr[i]);
    }
    // dest addr
    printf("\n the destination address is: ");
    for (int i=11; i<=15; i++){
        printf("%d", arr[i]);
    }
    // msg
    printf("\n the message is: ");
    for (int i=20; i<=30; i++){
        printf("%d", arr[i]);
    }

    return 0;
}