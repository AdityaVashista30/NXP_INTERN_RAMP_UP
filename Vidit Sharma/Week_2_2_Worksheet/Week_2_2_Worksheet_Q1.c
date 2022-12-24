#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct student{
    int prev_roll_no;
    char prev_sec;
    char new_sec;
    char new_roll_no;
    int sub[5];
    double percent;
};
struct section{
   struct student *arr;
};
bool check_vowel(char c){
  if(c=='A'||c=='E'||c=='I')return true;
  return false;
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
int main(){
    int sect_count=10;
    int append_c=65;
    int i=0;
    struct section obj[10];
    while(i<sect_count){
          char temp=(char)(append_c+i);
          if(check_vowel(temp)){
            obj[i].arr=malloc(25*sizeof(struct student));
            fill_in(obj[i],25,temp); 
          }
          else if(check_vowel(temp+1)){
            obj[i].arr=malloc(30*sizeof(struct student));
            fill_in(obj[i],30,temp+1);
          }
          else if(check_vowel(temp-1)){
             obj[i].arr=(struct student*)malloc(20*sizeof(struct student));
             fill_in(obj[i],20,temp-1);
          }
          else{
            obj[i].arr=(struct student*)malloc(22*sizeof(struct student));
            fill_in(obj[i],22,temp);
          }
          i+=1;
        }
       
    return 0;
}