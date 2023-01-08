#include <stdio.h>

int main() {
  // Prompt the user for the message unit
  printf("Enter the message unit: ");
  int message_unit;
  scanf("%X", &message_unit);
  
  // Extract the message id, source address, destination address, and data/message fields
  int message_id = message_unit >> 28;
  int source_addr = (message_unit >> 22) & 0x3F;
  int dest_addr = (message_unit >> 17) & 0x1F;
  int data = (message_unit >> 12) & 0x1F;
  
  // Print the extracted values
  printf("Message Id: %d\n", message_id);
  printf("Source Address: %d\n", source_addr);
  printf("Destination Address: %d\n", dest_addr);
  printf("Data/Message: %d\n", data);
  
  return 0;
}
