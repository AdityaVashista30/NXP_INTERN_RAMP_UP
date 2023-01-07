

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct rishi {
    int number;
    char* string;
    bool boolean;
};

int main(int argc, const char * argv[]) {
    struct rishi object[2];
    struct rishi* ptr;
    
    ptr = object;
    
    ptr->number = 8;
    ptr->string = "Rishi";
    ptr->boolean = false;
    
    
    (ptr+1)->number = 1;
    (ptr+1)->string = "Karan";
    (ptr+1)->boolean = true;
    
    for(int i=0;i<2;i++) {
        printf("%d. number = %d\n",i,(ptr+i)->number);
        printf("%d. string = %s\n",i,(ptr+i)->string);
        printf("%d. bool = %s\n",i,(ptr+i)->boolean ? "true" : "false");
    }
    
    
    return 0;
}
