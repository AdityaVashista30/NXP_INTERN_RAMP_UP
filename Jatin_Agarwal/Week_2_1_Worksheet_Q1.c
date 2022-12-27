#include<stdio.h>




    int (*fp)(int,int);
    int add(int x,int y){
      return x+y;
    } 

    int sub(int x,int y){
        return x-y;
    }
    int mul(int x,int y){
        return x*y;
    }

    void main(){
    int x,y;
    printf("Enter two numbers");
    scanf("%d%d",&x,&y);
    
    int choice;
    printf("Enter \n0. for add\n1. for subtract\n2. for multiply\n");
    scanf("%d",&choice);

    if(choice==0){
        fp = add;
        int z = (*fp)(x,y);
        printf("sum is = %d",z);
    }else if(choice==1){
        fp = sub;
         int z = (*fp)(x,y);
         printf("subtract is = %d",z);
    }else if(choice==2){
        fp = mul;
         int z = (*fp)(x,y);
         printf("multiply is = %d",z);
    }

    

}