#include "parser.h"
#include "types.h"

#include <stdio.h>

int main() {
  printf("Number of logical pages: %d\n", PAGE_COUNT);
  Address address;
  address_init(&address, 0x11223456);
  address_print(address);
}
