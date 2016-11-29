#include "parser.h" 
#include "types.h"
#include "tlb.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_ADDRESSES 100000
#define TEST_FILE "testinput.txt"

TLB tlb;

int combine_8_bit_numbers(uint8_t upper, uint8_t lower);

void init() {
  tlb_init(&tlb);
}

int main() {
  init();
  tlb_misses = 0; page_misses = 0; total_loads = 0;
  printf("Welcome to Group 9's VM Simulator Version 1.0\n\n");
  printf("Number of logical pages: %d\n", PAGE_COUNT);
  printf("Page size: %d bytes\n", PAGE_SIZE);
  printf("Page table size: %d\n", PAGE_TABLE_SIZE);
  printf("TLB size: %d entries\n", TLB_ENTRIES);
  printf("Number of physical frames: %d\n", FRAME_COUNT);
  printf("Physical memory size: %d bytes\n", PHYSICAL_MEMORY_SIZE);
  printf("Display Physical Addresses? [yes or no] \n");
  printf("Choose TLB Replacement Strategy [1: FIFO, 2: LRU] \n");
  int mode = 1;
  Address address;
  Address* addresses;
  int read;
  if (read_file(&addresses, &read) < 0) exit(1);
  int i;
  for (i = 0; i < read; i++) {
    FrameValue frame_value;
    printf("Looking up address, %u in tlb\n", combine_8_bit_numbers(addresses[i].page_number, addresses[i].offset));
    tlb_get(&tlb, addresses[i], mode, &frame_value);
    printf("Found frame value %u from address %u %u\n", frame_value, addresses[i].page_number, addresses[i].offset);
    total_loads++;
  }
  double page_miss_percentage = (double) page_misses / (double) total_loads * 100;
  double tlb_hit_rate = (double) (total_loads - tlb_misses) / (double) total_loads *100;
  printf("Page fault rate: %.1f%%\n", page_miss_percentage);
  printf("TLB hit rate: %.1f%%\n", tlb_hit_rate);
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
    Address* address = malloc(sizeof(Address));
    int bit_address = atoi(line);
    address_init(address, bit_address);
    stored[*read] = *address; 
    (*read)++;
  }
  *addresses = stored;

  return 0;
}

int combine_8_bit_numbers(uint8_t upper, uint8_t lower) {
  uint16_t upperByte = (uint16_t) upper;
  uint16_t sixteenBitNumber = 256*upperByte + lower;
  sixteenBitNumber = (upperByte<<8) | lower;
  return sixteenBitNumber;
}