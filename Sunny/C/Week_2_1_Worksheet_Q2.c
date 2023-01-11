#include<stdio.h>
#include<string.h>
struct stu {
   int a;
   int b;
};
int main(){
    struct stu obj1,obj2;
    struct stu (*ptr[2])={&obj1,&obj2};
    for(int i=0;i<2;i++){
    scanf("%d",&ptr[i]->a);
    scanf("%d",&ptr[i]->b);
    }
   for(int i=0;i<2;i++){
    printf("%d %d",ptr[i]->a,ptr[i]->b);
   }
    return 0;

}