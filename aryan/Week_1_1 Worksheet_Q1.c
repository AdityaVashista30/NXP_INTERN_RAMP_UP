#include <stdio.h>
#include <stdlib.h>

typedef union Info {
  u_int16_t data;
  char filler1;
  char filler2;
} Info;

typedef struct Obj {
  Info data;
  char* str;
  unsigned int bool:1;
} Obj;

void print_obj(Obj* object) {
  printf("%d\n", object->data);
  printf("%s\n", object->str);
  printf("%d\n", object->bool);
}

main() {
  Obj* obj = (Obj*)malloc(sizeof(Obj));

  obj->data = (Info)(u_int16_t)65588;
  obj->str = "worksheet_1 question 1 for c programming language";
  obj->bool = 3;

  print_obj(obj);

  return 0;
}
