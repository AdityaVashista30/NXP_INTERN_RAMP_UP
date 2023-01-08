#include <stdio.h>
#include <stdint.h>
 struct var{
     uint16_t a;
     char s[2];
 };
 int main()
 {
     struct var ob1;
     struct var *ob=&ob1;
     ob->a=13;
     ob->s[0]='a';
     ob->s[1]='b';
     printf("a=%X\n",ob->a);
     printf("s=%s",ob->s);
     return 0;
