
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StudentData {
    int number;
    char* string;
    bool boolean;
};

int main() {
    struct StudentData ob[2];
    struct StudentData* ptr;
    ptr=ob;
    ptr->number = 7;
    ptr->string = "Yug";
    ptr->boolean = true;
    (ptr+1)->number = 8;
    (ptr+1)->string = "Yash";
    (ptr+1)->boolean = true;
    
    for(int i=0;i<2;i++) {
        printf("%d number=%d\n",i,(ptr+i)->number);
        printf("%d string=%s\n",i,(ptr+i)->string);
        printf("%d bool=%s\n",i,(ptr+i)->boolean ? "true" : "false");
    }
    
    
    return 0;
}