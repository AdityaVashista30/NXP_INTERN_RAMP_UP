#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
  uint8_t command_id;
  uint8_t source;
  union {
    struct {
      uint32_t key_length;
      uint8_t key_type;
      bool is_private;
    } command1;
    struct {
      bool essential_core;
      uint8_t core_number;
    } command2;
    struct {
      uint16_t application_id;
      uint8_t application_type;
      uint8_t priority;
    } command3;
  } data;
} Command;

int main() {
  Command cmd;

  printf("Enter command id: ");
  scanf("%hhu", &cmd.command_id);
  printf("Enter source: ");
  scanf("%hhu", &cmd.source);

  switch (cmd.command_id) {
    case 1:
      printf("Enter key length: ");
      scanf("%u", &cmd.data.command1.key_length);
      printf("Enter key type: ");
      scanf("%hhx", &cmd.data.command1.key_type);
      printf("Enter is_private: ");
      scanf("%hhd", &cmd.data.command1.is_private);
      break;
    case 2:
      printf("Enter essential_core: ");
      scanf("%hhd", &cmd.data.command2.essential_core);
      printf("Enter core_number: ");
      scanf("%hhx", &cmd.data.command2.core_number);
      break;
    case 3:
      printf("Enter application_id: ");
      scanf("%hu", &cmd.data.command3.application_id);
      printf("Enter application_type: ");
      scanf("%hhx", &cmd.data.command3.application_type);
      printf("Enter priority: ");
      scanf("%hhu", &cmd.data.command3.priority);
      break;
    default:
      break;
  }

  return 0;
}
