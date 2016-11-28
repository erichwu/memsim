#include "parser.h"
#include "types.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_ADDRESSES 1000
#define TEST_FILE "testinput.txt"

int main() {
  printf("Welcome to Group 9's VM Simulator Version 1.0\n\n");
  printf("Number of logical pages: %d\n", PAGE_COUNT);
  printf("Page size: %d bytes\n", PAGE_SIZE);
  printf("Page table size: %d\n", PAGE_TABLE_SIZE);
  printf("TLB size: %d entries\n", TLB_ENTRIES);
  printf("Number of physical frames: %d\n", FRAME_COUNT);
  printf("Physical memory size: %d bytes\n", PHYSICAL_MEMORY_SIZE);
  Address address;
  Address* addresses;
  int read;
  if (read_file(&addresses, &read) < 0) exit(1);
  int i;
  for (i = 0; i < read; i++) {
    address_print(addresses[i]);
  }
}

// read_file containing 32-bit addresses.
//
// Results are stored in the addresses parameter.
//
// The length of the addresses array is stored in the read parameter.
int read_file(Address** addresses, int* read) {
  Address stored[MAX_ADDRESSES];
  FILE* file_pointer;
  char* line = NULL;
  size_t buf_length = 0;
  ssize_t line_length;
  *read = 0;
  file_pointer = fopen(TEST_FILE, "r");
  if (file_pointer == NULL) return -1;

  while ((line_length = getline(&line, &buf_length, file_pointer))  != -1) {
    Address address;
    int bit_address = atoi(line);
    address_init(&address, bit_address);
    stored[*read] = address; 
    (*read)++;
  }
  *addresses = stored;

  return 0;
}
