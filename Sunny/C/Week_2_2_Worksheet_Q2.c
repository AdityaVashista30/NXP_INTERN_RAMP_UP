#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct student{
    int sub[5];
    int total;
    double per;
};
struct school{
    struct student *structclass;
};
struct section{
    struct student *student;
    int roll;
    char se;
};
int check(char i){
    if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u')
        return 1;
    return 0;
}
int set_total_marks(struct school* st,int n){
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=0;j<5;j++) temp+=st->structclass[i].sub[j];
        st->structclass[i].total = temp;
        st->structclass[i].per = (((double)temp)/500)*100;
    }
}
void print_school(struct school *temp,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++) printf("%d ",temp->structclass[i].sub[j]);
        printf("%d ",temp->structclass[i].total);
        printf("%f ",temp->structclass[i].per);
        printf("\n");
    }
}
void swap(struct student *a,struct student *b){
    struct student temp = *a;
    *a = *b;
    *b = temp;
}
void sort(struct student temp[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(temp[j].per>temp[j+1].per)
                swap(&temp[j],&temp[j+1]);
        }
    }
}
void question_a(struct school *temp,int size[]){
    for(int i=0;i<10;i++){
        printf("top 5 students of %d section \n",(i+1));
        for(int j=size[i]-1;j>=size[i]-6;j--){
            for(int k=0;k<5;k++) printf("%d ",temp[i].structclass[j].sub[k]);
            printf("%f\n",temp[i].structclass[j].per);
        }
        printf("\n");
    }
}
void question_b(struct school *temp,int size[]){
    struct student *arr;
    for(int i=0;i<10;i++) arr[i] = temp[i].structclass[size[i]-1];
    sort(arr,10);
    for(int i=9,j=1;i>=0 && j<=10;i--,j++){
        printf("top %d student ",(j));
        for(int j=0;j<5;j++) printf("%d ",arr[i].sub[j]);
        printf("%f\n",arr[i].per);
        printf("\n");
    }
}
void sort_each_sub(struct student *temp[],int n,int mod){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(temp[j]->sub[mod]>temp[j+1]->sub[mod]){
                //swap_(temp[j],temp[j+1]);
                struct student *t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
            }
        }
    }
}
void question_c(struct school *temp,int size[]){
    int top = 0,n=0;
    for(int i=0;i<10;i++) n+=size[i];
    struct student *arr[n];
    for(int i=0;i<10;i++) for(int j=0;j<size[i];j++) arr[top++] = &temp[i].structclass[j];
    printf("%d\n",top);
//    for(int i=0;i<top;i++){
//        for(int j=0;j<5;j++) printf("%d ",arr[i]->sub[j]);
//        printf("%f\n",arr[i]->per);
//    }
    for(int s=0;s<5;s++){
        sort_each_sub(arr,top,s);
        printf("top 20 student of subject %d\n",s+1);
        for(int i=top-1;i>=top-21;i--){
            for(int j=0;j<5;j++) printf("%d ",arr[i]->sub[j]);
            printf("%f\n",arr[i]->per);
        }
        printf("\n");
    }
}
void sort_each(struct student *temp[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(temp[j]->per>temp[j+1]->per){
                //swap_(temp[j],temp[j+1]);
                struct student *t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
            }
        }
    }
}
void question_3(struct school *temp,int size[]){
    int n = 0,top = 0;
    for(int i=0;i<10;i++) n+=size[i];
    struct student *arr[n];
    for(int i=0;i<10;i++) for(int j=0;j<size[i];j++) arr[top++] = &temp[i].structclass[j];
    sort_each(arr,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++) printf("%d ",arr[i]->sub[j]);
        printf("%f\n",arr[i]->per);
    }
    printf("%d\n",n);
    int roll = 1;
    char se = 'a';
    struct section *section[10];
    top--;
    for(char i='a';i<='j';i++){
        if(check(i)){
            section[i-'a'] = (struct section*) malloc(25*(sizeof(struct section)));
            for(int j=0;j<25;j++){
                section[i-'a'][j].se = se;
                section[i-'a'][j].student = arr[top--];
                section[i-'a'][j].roll = roll++;
            }
            se++;
        }else if(check((char)(i+1))){
            section[i-'a'] = (struct section*) malloc(20*(sizeof(struct section)));
            for(int j=0;j<20;j++){
                section[i-'a'][j].se = se;
                section[i-'a'][j].student = arr[top--];
                section[i-'a'][j].roll = roll++;
            }
            se++;
        }else if(check((char)(i-1))){
            section[i-'a'] = (struct section*) malloc(30*(sizeof(struct section)));
            for(int j=0;j<30;j++){
                section[i-'a'][j].se = se;
                section[i-'a'][j].student = arr[top--];
                section[i-'a'][j].roll = roll++;
            }
            se++;
        }else{
            section[i-'a'] = (struct section*) malloc(22*(sizeof(struct section)));
            for(int j=0;j<22;j++){
                section[i-'a'][j].se = se;
                section[i-'a'][j].student = arr[top--];
                section[i-'a'][j].roll = roll++;
            }
            se++;
        }
        //printf("%d\n",top);
    }
    for(int i=0;i<10;i++){
        printf("section %c\n",(char)(i+'a'));
        for(int j=0;j<size[i];j++) {
            printf("%d ",section[i][j].roll);
            printf("%f\n",section[i][j].student->per);
        }
        printf("\n");
    }
}
int main(){
    struct school structschool[10];
    int size[10];
    //structschool.structclass = (int*) malloc(10*sizeof(struct student));
    for(char i='a';i<='j';i++){
        if(check(i)) {
            structschool[i - 'a'].structclass = (struct student*) malloc(25 * sizeof(struct student));
            size[i-'a'] = 25;
            printf("add 25 entries");
            for(int u=0;u<25;u++){
                int input;
                for(int v=0;v<5;v++){
                    scanf("%d",&input);
                    structschool[i-'a'].structclass[u].sub[v] = input;
                }
            }
        }
        else if(check((char)(i+1))) {
            structschool[i - 'a'].structclass = (struct student*) malloc(20 * sizeof(struct student));
            size[i-'a'] = 20;
            printf("add 20 entries");
            for(int u=0;u<20;u++){
                for(int v=0;v<5;v++){
                    int input;
                    scanf("%d",&input);
                    structschool[i-'a'].structclass[u].sub[v] = input;
                }
            }
        }
        else if(check((char)(i-1))) {
            structschool[i - 'a'].structclass = (struct student *) malloc(30 * sizeof(struct student));
            size[i-'a'] = 30;
            printf("add 30 entries");
            for(int u=0;u<30;u++){
                for(int v=0;v<5;v++){
                    int input;
                    scanf("%d",&input);
                    structschool[i-'a'].structclass[u].sub[v] = input;
                }
            }
        }
        else {
            structschool[i - 'a'].structclass = (struct student*) malloc(22 * sizeof(struct student));
            size[i-'a'] = 22;
            printf("add 22 entries");
            for(int u=0;u<22;u++){
                for(int v=0;v<5;v++){
                    int input;
                    scanf("%d",&input);
                    structschool[i-'a'].structclass[u].sub[v] = input;
                }
            }
        }
    }
    for(int i=0;i<10;i++) set_total_marks(&structschool[i],size[i]);
    for(int i=0;i<10;i++) sort(structschool[i].structclass,size[i]);
    for(int i=0;i<10;i++) print_school(&structschool[i],size[i]);
    question_a(structschool,size);
    question_b(structschool,size);
    question_c(structschool,size);
    question_3(structschool,size);
}