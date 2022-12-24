// Q2. Once database is created
//  	a. print top 5 students of each section based on %
// 	b. print top 10 students in all sections based on %
// 	c. print top 20 students in each individual subject in all sections
// 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//priority queue would be very efficeint compared to naive searching 
// implementation difficult in c
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
int mycmp20_1(const void *p, const void *q) 
{
    int l = ((struct student *)p)->sub[0];
    int r = ((struct student *)q)->sub[0]; 
     if(r>l)return 1;
    return -1;
}
int mycmp20_2(const void *p, const void *q){
    int l = ((struct student *)p)->sub[1];
    int r = ((struct student *)q)->sub[1]; 
     if(r>l)return 1;
    return -1;

}
int mycmp20_3(const void *p, const void *q){
    int l = ((struct student *)p)->sub[2];
    int r = ((struct student *)q)->sub[2]; 
     if(r>l)return 1;
    return -1;
}
int mycmp20_4(const void *p, const void *q){
    int l = ((struct student *)p)->sub[3];
    int r = ((struct student *)q)->sub[3]; 
     if(r>l)return 1;
    return -1;
}
int mycmp20_5(const void *p, const void *q){
    int l = ((struct student *)p)->sub[4];
    int r = ((struct student *)q)->sub[4]; 
     if(r>l)return 1;
    return -1;
}
void printtop5(struct section *obj){
     for(int i=0;i<10;i++){
        qsort(obj[i].arr, obj[i].sz, sizeof(struct student), mycmp);
       // qsort(obj[i].arr,obj[i].arr+25,mycmp());
     }
     for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            printf(" roll-no %d percent %lf section %c\n",obj[i].arr[j].prev_roll_no,obj[i].arr[j].percent,obj[i].arr[j].prev_sec);
        }
     }
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
       return allstud;
}
void printtop10(struct student *allstudents){
       qsort(allstudents, tot, sizeof(struct student), mycmp10);
       for(int i=0;i<10;i++){
        printf(" roll no %d section %c percent %lf \n",allstudents[i].prev_roll_no,allstudents[i].prev_sec,allstudents[i].percent);
       }
}
void printtop20(struct student *allstudents){
    qsort(allstudents, tot, sizeof(struct student), mycmp20_1);
    printf(" ************ subject1 ***************** \n");
       for(int i=0;i<20;i++){
        printf(" roll no %d section %c sub marks %d 1 \n",allstudents[i].prev_roll_no,allstudents[i].prev_sec,allstudents[i].sub[0]);
       }
      qsort(allstudents, tot, sizeof(struct student), mycmp20_2);
      printf(" ************ subject2 ***************** \n");
       for(int i=0;i<20;i++){
        printf(" roll no %d section %c sub marks %d 2 \n",allstudents[i].prev_roll_no,allstudents[i].prev_sec,allstudents[i].sub[1]);
       }
       qsort(allstudents, tot, sizeof(struct student), mycmp20_3);
       printf(" ************ subject3 ***************** \n");
       for(int i=0;i<20;i++){
        printf(" roll no %d section %c sub marks %d 3 \n",allstudents[i].prev_roll_no,allstudents[i].prev_sec,allstudents[i].sub[2]);
       }
      qsort(allstudents, tot, sizeof(struct student), mycmp20_4);
      printf(" ************ subject4 ***************** \n");
       for(int i=0;i<20;i++){
        printf(" roll no %d section %c sub marks %d 4 \n",allstudents[i].prev_roll_no,allstudents[i].prev_sec,allstudents[i].sub[3]);
       }
      qsort(allstudents, tot, sizeof(struct student), mycmp20_5);
      printf(" ************ subject5 ***************** \n");
       for(int i=0;i<20;i++){
        printf(" roll no %d section %c sub marks %d 5 \n",allstudents[i].prev_roll_no,allstudents[i].prev_sec,allstudents[i].sub[4]);
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
    printf(" printing top 5 in each section \n");
    printtop5(obj);
    printf(" ****************************** \n\n");
    printf(" pritning top 10 overall \n");
    printtop10(allstudents);
    printf(" *******************************\n\n");
    printf(" top 20 in seach of the 5 subjects \n");
    printtop20(allstudents); 
    return 0;
}