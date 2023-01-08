#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool isVowel(char c){
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    return true;
    return false;
}
struct student{
    int subject_marks[5];
    char section_name;
    int roll_no;
    char old_section_name;
    int old_roll_no;
};
struct classes{
    int size;
    char class_name;
    struct student *student_arr_ptr;

};
void generate_database(struct classes *section){
    for(char i='A';i<='J';i++){
        section[i-'A'].class_name=i;
        if(isVowel(i)){
            section[i-'A'].student_arr_ptr=(struct student*) malloc(25*sizeof(struct student));
            section[i-'A'].size=25;
        }
        else if(isVowel(i+1)){
            section[i-'A'].student_arr_ptr=(struct student*) malloc(20*sizeof(struct student));           
            section[i-'A'].size=20;
        }
        else if(isVowel(i-1)){
            section[i-'A'].student_arr_ptr=(struct student*) malloc(30*sizeof(struct student));           
            section[i-'A'].size=30;
        }
        else{
            section[i-'A'].student_arr_ptr=(struct student*) malloc(22*sizeof(struct student));           
            section[i-'A'].size=22;

        }
        for(int j=0;j<section[i-'A'].size;j++){
            section[i-'A'].student_arr_ptr[j].roll_no=j;
            section[i-'A'].student_arr_ptr[j].section_name=i;
            section[i-'A'].student_arr_ptr[j].subject_marks[0]=rand()%101;
            section[i-'A'].student_arr_ptr[j].subject_marks[1]=rand()%101;
            section[i-'A'].student_arr_ptr[j].subject_marks[2]=rand()%101;
            section[i-'A'].student_arr_ptr[j].subject_marks[3]=rand()%101;
            section[i-'A'].student_arr_ptr[j].subject_marks[4]=rand()%101;
        }
    }
}
void print_database(struct classes *section,int trap){
        for(char i='A';i<='J';i++){
        printf("\nSECTION -- %c\nSize: %d\n",i,section[i-'A'].size);
        for(int j=0;j<section[i-'A'].size;j++){
            printf("\nRoll No.: %d\nSection Name: %c",section[i-'A'].student_arr_ptr[j].roll_no,section[i-'A'].student_arr_ptr[j].section_name);
            if(trap==1){
            printf("\nOld Roll No.: %d\nOld Section Name: %c",section[i-'A'].student_arr_ptr[j].old_roll_no,section[i-'A'].student_arr_ptr[j].old_section_name);
            }
            printf("\nMarks: "); 
            for(int k=0;k<5;k++){
                printf(" %d ",section[i-'A'].student_arr_ptr[j].subject_marks[k]);
            }
            printf("\n");
        }
        printf("\n\n\n");
    }
}
int sum_of_marks(int *arr){
int sum=0;
for(int i=0;i<5;i++){
    sum+=arr[i];
}
return sum;
}
int comparator(const void *p, const void *q)
{
    struct student *l = ( struct student *)p;
    struct student *r = ( struct student *)q;
    return sum_of_marks(r->subject_marks)-sum_of_marks(l->subject_marks);
}
int subject_comparator(void *m,const void *p, const void *q)
{
    int i=(*(int*)m);
    struct student *l = ( struct student *)p;
    struct student *r = ( struct student *)q;
    return r->subject_marks[i]-l->subject_marks[i];
}
void top5_eachClass(struct classes *section){ 
        printf("\n-----------------------Q2.a--------------------");   
    for(char i='A';i<='J';i++){
        printf("\nSection %c\n",i);
        struct student *temp_student_arr;
        temp_student_arr=(struct student*)malloc(section[i-'A'].size*sizeof(struct student));
        for(int j=0;j<section[i-'A'].size;j++){
            temp_student_arr[j]=section[i-'A'].student_arr_ptr[j];
        }
        qsort(temp_student_arr, section[i-'A'].size, sizeof(struct student), comparator);
       printf("\nTop 5 students (In each class) are with roll no.:\n%d, %d, %d, %d, %d\n",temp_student_arr[0].roll_no,temp_student_arr[1].roll_no,temp_student_arr[2].roll_no,temp_student_arr[3].roll_no,temp_student_arr[4].roll_no);
       }
           printf("\n-------------------------------------------");
    printf("\n\n\n");
}
void top10_wholeSection(struct classes *section){
    printf("\n-----------------------Q2.b--------------------");
    int total_size=0;
    for(char i='A';i<='J';i++){
        total_size+=section[i-'A'].size;
    }
    printf("\nTotal Students: %d\n",total_size);
    struct student *temp_student_arr;
    temp_student_arr=(struct student*)malloc(total_size*sizeof(struct student));
    int k=0;
    for(char i='A';i<='J';i++){
        for(int j=0;j<section[i-'A'].size;j++){
            temp_student_arr[k]=section[i-'A'].student_arr_ptr[j];
            k++;
        }
    }
    qsort(temp_student_arr, total_size, sizeof(struct student), comparator);
    printf("\nTop 10 students overall are: \n");
    for(int i=0;i<10;i++){
        printf("\nSection: %c\nRoll No.: %d\nSum of marks: %d\n",temp_student_arr[i].section_name,temp_student_arr[i].roll_no,sum_of_marks(temp_student_arr[i].subject_marks));
    }
    printf("\n-------------------------------------------");
    printf("\n\n\n");
}
void top20_eachSubjet(struct classes *section){
    printf("\n-----------------------Q2.c--------------------");
    int total_size=0;
    for(char i='A';i<='J';i++){
        total_size+=section[i-'A'].size;
    }
    printf("\nTotal Students: %d\n",total_size);
    struct student *temp_student_arr;
    temp_student_arr=(struct student*)malloc(total_size*sizeof(struct student));
    int k=0;
    for(char i='A';i<='J';i++){
        for(int j=0;j<section[i-'A'].size;j++){
            temp_student_arr[k]=section[i-'A'].student_arr_ptr[j];
            k++;
        }
    }
    for(int m=0;m<5;m++){
    qsort_s(temp_student_arr, total_size, sizeof(struct student), subject_comparator,&m);
        printf("\nTop 20 students overall in subject %d are: \n",m+1);
    for(int i=0;i<20;i++){
        printf("\nSection: %c\nRoll No.: %d\nMarks in suject: %d\n",temp_student_arr[i].section_name,temp_student_arr[i].roll_no,temp_student_arr[i].subject_marks[m]);
    }
    }

    printf("\n-------------------------------------------");
    printf("\n\n\n");
}
void shuffle_class(struct classes *section){
    printf("\n-----------------------Q3--------------------");
    int total_size=0;
    for(char i='A';i<='J';i++){
        total_size+=section[i-'A'].size;
    }
    printf("\nTotal Students: %d\n",total_size);
    struct student *temp_student_arr;
    temp_student_arr=(struct student*)malloc(total_size*sizeof(struct student));
    int k=0;
    for(char i='A';i<='J';i++){
        for(int j=0;j<section[i-'A'].size;j++){
            temp_student_arr[k]=section[i-'A'].student_arr_ptr[j];
            k++;
        }
    } 
    k=0;
    qsort(temp_student_arr, total_size, sizeof(struct student), comparator);
    for(char i='A';i<='J';i++){
        for(int j=0;j<section[i-'A'].size;j++){
            section[i-'A'].student_arr_ptr[j]=temp_student_arr[k];
            section[i-'A'].student_arr_ptr[j].old_roll_no=section[i-'A'].student_arr_ptr[j].roll_no;
            section[i-'A'].student_arr_ptr[j].old_section_name=section[i-'A'].student_arr_ptr[j].section_name;
            section[i-'A'].student_arr_ptr[j].roll_no=j;
            section[i-'A'].student_arr_ptr[j].section_name=i;
            k++;
        }
    }

}
int main()
{
    struct classes section['J'-'A'+1];
    //Q1
    generate_database(section);
    print_database(section,0);
    //Q2
    top5_eachClass(section);
    top10_wholeSection(section);
    top20_eachSubjet(section);
    //Q3
    shuffle_class(section);
    print_database(section,1);

    return 0;
}