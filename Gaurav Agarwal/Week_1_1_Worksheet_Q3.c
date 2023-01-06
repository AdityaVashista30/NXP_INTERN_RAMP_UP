#include <stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>
struct st
{
  int32_t a;
  uint16_t b;
  char s[20];
  bool c;

};
int
main ()
{
  struct st s1;
  struct st *s2 = &s1;
  s2->a = 32;
  s2->b = 45;
  strcpy (s2->s, "hello");
  s2->c = 1;
  printf ("%x \n", s2->a);
  printf ("%x \n", s2->b);
  printf("%s \n",s2->s); 
  printf("%d \n",s2->c); 


  return 0;
}