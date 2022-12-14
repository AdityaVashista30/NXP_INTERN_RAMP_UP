#include<stdio.h>
#include<string.h>
struct nxp {
   int a;
   char name[50];
   int b;
};
int main(){
    struct nxp obj1,obj2;
    struct nxp (*ptr[2])={&obj1,&obj2};
    for(int i=0;i<2;i++){
    scanf("%d",&ptr[i]->a);
    scanf("%s",ptr[i]->name);
    scanf("%d",&ptr[i]->b);
    }
   for(int i=0;i<2;i++){
    printf("%d %d",ptr[i]->a,ptr[i]->b);
    printf(" %s \n",ptr[i]->name);
   }
    return 0;

}