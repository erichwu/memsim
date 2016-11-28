#include "parser.h"
#include "types.h"

#include <stdio.h>

int main() {
  printf("Welcome to Group 9's VM Simulator Version 1.0\n\n");
  printf("Number of logical pages: %d\n", PAGE_COUNT);
  printf("Page size: %d bytes\n", PAGE_SIZE);
  printf("Page table size: %d\n", PAGE_TABLE_SIZE);
  printf("TLB size: %d entries\n", TLB_ENTRIES);
  printf("Number of physical frames: %d\n", FRAME_COUNT);
  printf("Physical memory size: %d bytes\n", PHYSICAL_MEMORY_SIZE);
  Address address;
  address_init(&address, 22760);
  address_print(address);
}
