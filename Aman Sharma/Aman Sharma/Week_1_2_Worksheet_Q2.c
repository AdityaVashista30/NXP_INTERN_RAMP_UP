#include <stdio.h>

int main() {
  // Prompt the user for the inputs
  printf("Enter bits 1-4 (Message Id): ");
  int message_id;
  scanf("%d", &message_id);
  
  printf("Enter bits 5-10 (Source Address): ");
  int source_addr;
  scanf("%d", &source_addr);
  
  printf("Enter bits 11-15 (Destination Address): ");
  int dest_addr;
  scanf("%d", &dest_addr);
  
  printf("Enter bits 20-30 (Data/Message): ");
  int data;
  scanf("%d", &data);
  
  // Create the 32-bit number
  int num = (message_id << 28) | (source_addr << 22) | (dest_addr << 17) | (data << 12) | 0x7FF;
  
  // Print the number in hexadecimal format
  printf("0x%X\n", num);
  
  return 0;
}
