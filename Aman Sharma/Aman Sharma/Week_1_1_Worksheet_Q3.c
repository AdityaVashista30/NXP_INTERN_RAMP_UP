#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  uint32_t data;
  char str[16];
  uint8_t binary[4];
} MyStruct;

int main() {
  // Create a pointer to a MyStruct object
  MyStruct *s = malloc(sizeof(MyStruct));
  
  // Set the values of the fields
  s->data = 65535;
  strcpy(s->str, "Hello World");
  s->binary[0] = 1;
  s->binary[1] = 0;
  s->binary[2] = 1;
  s->binary[3] = 0;
  
  // Print the values of the fields
  printf("Data: 0x%X\n", s->data);
  printf("String: %s\n", s->str);
  printf("Binary: %d%d%d%d\n", s->binary[0], s->binary[1], s->binary[2], s->binary[3]);
  
  // Free the memory allocated for the object
  free(s);
  
  return 0;
}
