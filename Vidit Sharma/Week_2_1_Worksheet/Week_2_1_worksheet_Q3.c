#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
union nxp
{
    struct comp1{
        int len;
        unsigned int type;
        bool ispvt;
    }a;
    struct comp2{
     bool essential_core;
     unsigned int core_num;
    }b;
    struct comp3{
        int16_t app_id;
        int8_t app_type;
        int8_t priority_id;
    }c;

};
void disp(int ch,union nxp obj){
   if(ch==1){
    printf(" key length ");
    printf("%d\n",obj.a.len);
    printf(" key type  ");
    printf("%u\n",obj.a.type);
    printf(" isprivate ");
    printf("%d\n",obj.a.ispvt);
   }
   else if(ch==2){
    printf(" essential core ");
    printf("%d\n",obj.b.essential_core);
    printf(" core num ");
    printf("%u\n",obj.b.core_num);
    //("%u",&obj.a.type);
   }
   else {
    printf(" application id ");
    printf("%d\n",obj.c.app_id);
    printf(" application type ");
    printf("%d\n",obj.c.app_type);
    printf("  priority id ");
    printf("%d\n",obj.c.priority_id);
   }
}
int main(){
   union nxp obj;
   // single instance for all the options
   int sz=sizeof(obj);
   printf("size of obj is%d\n ",sz);
   int ch;
   do{
    printf(" Enter your choice from 1 to 3 and any other number to exit\n");
    scanf("%d",&ch);
    //
    if(ch<0||ch>3){
    printf(" exit ... \n");
    return 0;
   }
   //
    if(ch==1){
    scanf("%d",&obj.a.len);
    scanf("%u",&obj.a.type);
    scanf("%d",&obj.a.ispvt);
   }
   else if(ch==2){
    obj.b.essential_core=true;
    scanf("%u",&obj.b.core_num);
    //("%u",&obj.a.type);
   }
   else {
    scanf("%d",&obj.c.app_id);
    scanf("%d",&obj.c.app_type);
    scanf("%d",&obj.c.priority_id);
   }
   disp(ch,obj);
  }while(1);

    return 0;
}