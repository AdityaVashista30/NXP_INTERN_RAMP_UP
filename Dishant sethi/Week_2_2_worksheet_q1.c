#include <stdio.h>
 #include <stdlib.h>
 struct clas{
     int totalcountt;
     int curcount;
     char sec;
     struct data *students;
 };
 struct data{
     float marks[5];
     int roll;
     float perc;
 };

 int main()
 {
     struct clas class[10];   //0=A,1=B,...,9=J
     for(int i=0;i<10;i++){
         if(('A'+i)=='A'||('A'+i)=='E'||('A'+i)=='I'){
             class[i].totalcountt=25;
         }
         else if(('A'+i+1)=='A'||('A'+i+1)=='E'||('A'+i+1)=='I'){
             class[i].totalcountt=30;
         }
         else if(('A'+i-1)=='A'||('A'+i-1)=='E'||('A'+i-1)=='I'){
             class[i].totalcountt=20;
         }
         else{
             class[i].totalcountt=22;
         }
         class[i].sec='A'+i;
         class[i].curcount=0;
         struct data stu[class[i].totalcountt];
         class[i].students=stu;
     }
     while(1){
         int a;
         printf("Press '0' to enter data of a new student.\nPress '1' to view data\nPress '2' to exit program\n");
         scanf("%d",&a);
         if(a==2){
             printf("Exiting program...\n");
             exit(0);
         }
         if(a==1){
             int ch,rno;
             printf("Enter the class secion(from A=0 to J=9)\n");
             scanf("%d",&ch);
             if(class[ch].curcount==0){
                 printf("No data available for this class section.\n");
             }
             else{
                 printf("Enter the student's roll number\n");
                 scanf("%d",&rno);
                 if(class[ch].curcount>=rno){
                     for(int y=0;y<5;y++){
                         printf("Marks in subject %d=%f\n",y+1,class[ch].students[rno-1].marks[y]);
                     }
                     printf("Average percentage of student=%f\n",class[ch].students[rno-1].perc);
                 }
                 else{
                     printf("No data available for entered roll number.\n");
                 }
             }
         }
         else if(a==0){
             int j;
             float marks,totalmarks=0;
             int rno;
             printf("Enter the class secion(from A=0 to J=9)\n");
             scanf("%d",&j);
             printf("Enter the student's roll number\n");
             scanf("%d",&rno);
             if(class[j].curcount==class[j].totalcountt){
                 printf("Class is full\n");
             }
             else if(class[j].curcount<rno&&rno<=class[j].totalcountt){
                 class[j].curcount=class[j].curcount+1;
                 printf("Enter the student's marks in subjects A,B,C,D and E respectively.\n");
                 class[j].students[rno-1].roll=rno;
                 for(int y=0;y<5;y++){
                     scanf("%f",&marks);
                     class[j].students[rno-1].marks[y]=marks;
                     totalmarks=totalmarks+marks;
                 }
                 class[j].students[rno-1].perc=totalmarks/5;
             }
             else if(rno>class[j].totalcountt){
                 printf("Enter a valid roll number\n");
             }
             else{
                 printf("Student's data already present in database\n");
             }

         }

         else{
             printf("Enter a valid input\n");
         }
     }
 }
 