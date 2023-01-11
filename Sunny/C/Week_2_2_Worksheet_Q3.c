#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int tot=0;
struct student{
    int prev_roll_no;
    char prev_sec;
    char new_sec;
    char new_roll_no;
    int sub[5];
    double percent;
};
struct section{
   int sz;
   struct student *arr;
};
bool check_vowel(char c){
  if(c=='A'||c=='E'||c=='I')return true;
  return false;
}
// int mycmp(struct student a,struct student b){
//    return a.percent>b.percent;
// }
int mycmp(const void *p, const void *q) 
{
    double l = ((struct student *)p)->percent;
    double r = ((struct student *)q)->percent; 
     if(r>l)return 1;
    return -1;
}
int mycmp10(const void *p, const void *q) 
{
    double l = ((struct student *)p)->percent;
    double r = ((struct student *)q)->percent; 
    if(r>l)return 1;
    return -1;
}
void fill_in(struct section obj,int n,char temp){
     int i=0;
     while(i<n){
        obj.arr[i].prev_roll_no=rand()%n;
        obj.arr[i].prev_sec=temp;
        int sum=0;
        obj.arr[i].sub[0]=rand()%101;
        sum+=obj.arr[i].sub[0];
        obj.arr[i].sub[1]=rand()%101;
        sum+=obj.arr[i].sub[1];
        obj.arr[i].sub[2]=rand()%101;
        sum+=obj.arr[i].sub[2];
        obj.arr[i].sub[3]=rand()%101;
        sum+=obj.arr[i].sub[3];
        obj.arr[i].sub[4]=rand()%101;
        sum+=obj.arr[i].sub[4];  
        obj.arr[i].percent=(double)sum/5.0;
        i+=1;
     }

}
struct student * getallstud(struct section *obj){
       struct student *allstud;
       allstud=(struct student*)malloc(tot*sizeof(struct student));
       int szz=0;
       for(int i=0;i<10;i++){
        for(int j=0;j<obj[i].sz;j++){
           allstud[szz] =obj[i].arr[j];
           szz+=1;
        }
       }
       printf(" %d ",szz);
       return allstud;
}  
void reassignment(struct student *allstudents,struct section *obj){
    char t='A';int idx=0;
    int c=0;
    while(c<10){
    if(check_vowel(t)){
      for(int i=0;i<25;i++){
        obj[c].arr[i].percent=allstudents[idx].percent;
        obj[c].arr[i].new_roll_no=i+1;
        obj[c].arr[i].new_sec=t;
      }
      t=(t+1);
      c+=1;
      idx+=25;
    }
    else if(check_vowel(t-1)){
      for(int i=0;i<20;i++){
        obj[c].arr[i].percent=allstudents[idx].percent;
        obj[c].arr[i].new_roll_no=i+1;
        obj[c].arr[i].new_sec=t;
      }
      c+=1;
      t=(t+1);
      idx+=20;
    }
    else if(check_vowel(t+1)){
              for(int i=0;i<30;i++){
        obj[c].arr[i].percent=allstudents[idx].percent;
        obj[c].arr[i].new_roll_no=i+1;
        obj[c].arr[i].new_sec=t;
      }
      t=(t+1);
      c+=1;
      idx+=30;
    }
    else{
                for(int i=0;i<22;i++){
        obj[c].arr[i].percent=allstudents[idx].percent;
        obj[c].arr[i].new_roll_no=i+1;
        obj[c].arr[i].new_sec=t;
      }
      t=(t+1);
      c+=1;
      idx+=22;
    }
    }
     for(int i=0;i<10;i++){
        for(int j=0;j<obj[i].sz;j++){
            printf(" roll-no %d percent %lf section %c new roll-no %d new section %c \n",obj[i].arr[j].prev_roll_no,obj[i].arr[j].percent,obj[i].arr[j].prev_sec,obj[i].arr[j].new_roll_no,obj[i].arr[j].new_sec);
        }
     }
}
int main(){
    int sect_count=10;
    int append_c=65;
    int i=0;
    struct section obj[10];
    while(i<sect_count){
          char temp=(char)(append_c+i);
          if(check_vowel(temp)){
            obj[i].arr=malloc(25*sizeof(struct student));
            obj[i].sz=25;
            tot+=25;
            fill_in(obj[i],25,temp); 
          }
          else if(check_vowel(temp+1)){
            obj[i].sz=30;
            tot+=30;
            obj[i].arr=malloc(30*sizeof(struct student));
            fill_in(obj[i],30,temp);
          }
          else if(check_vowel(temp-1)){
             obj[i].sz=20;
             tot+=20;
             obj[i].arr=(struct student*)malloc(20*sizeof(struct student));
             fill_in(obj[i],20,temp);
          }
          else{
            obj[i].sz=22;
            tot+=22;
            obj[i].arr=(struct student*)malloc(22*sizeof(struct student));
            fill_in(obj[i],22,temp);
          }
          i+=1;
        }
    struct student *allstudents=getallstud(obj);
    qsort(allstudents, tot, sizeof(struct student), mycmp10);
    reassignment(allstudents,obj);

    return 0;
}