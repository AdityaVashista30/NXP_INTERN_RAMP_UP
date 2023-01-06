#include <stdio.h>
#include<string.h>
struct s{
    int a;
    char s[20];
};
int main()
{
    struct s s1;
    struct s *s2;
    s2=&s1;
    //initializing using pointers
    s2->a=5;
    strcpy(s2->s,"hello");
    //creating 1d array
    struct s s3[2];
    s2=s3;
    s2->a=1;
    strcpy(s2->s,"hello");
    (s2+1)->a=2;
    strcpy((s2+1)->s,"gaurav");
    for(int i=0;i<2;i++){
    printf("%d ",(s2+i)->a);
        printf("%s \n",(s2+i)->s);
    }
    return 0;
}