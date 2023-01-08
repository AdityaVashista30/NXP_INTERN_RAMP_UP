#include <stdio.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

int main() {
  // Function pointers for the three operations
  int (*op[3])(int, int) = {add, subtract, multiply};
  
  // Prompt the user for the operation
  printf("Enter a number between 0 and 2 to choose an operation:\n");
  printf("0 - Add\n");
  printf("1 - Subtract\n");
  printf("2 - Multiply\n");
  int choice;
  scanf("%d", &choice);
  
  // Prompt the user for the operands
  printf("Enter the operands: ");
  int a, b;
  scanf("%d%d", &a, &b);
  
  // Perform the chosen operation
  int result = op[choice](a, b);
  
  // Print the result
  printf("Result: %d\n", result);
  
  return 0;
}

// Addition function
int add(int a, int b) {
  return a + b;
}

// Subtraction function
int subtract(int a, int b) {
  return a - b;
}

// Multiplication function
int multiply(int a, int b) {
  return a * b;
}
