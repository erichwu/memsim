#include "types.h"
#include "tlb.h"
#include "parser.h"

uint16_t make_uint16_t(uint32_t address) {
  return (uint16_t) (address >> BITS_PER_BYTE*sizeof(uint16_t));
}

PageNumber page_number(uint16_t address) {
  return (PageNumber) (address >> BITS_PER_BYTE*sizeof(uint8_t));
}

Offset offset(uint16_t address) {
  return (Offset) address;
}

void address_init(Address* address, uint32_t address_32_bit) {
  uint16_t address_16_bit = make_uint16_t(address_32_bit);
  address->page_number = page_number(address_16_bit);
  address->offset = offset(address_16_bit);
}

void address_print(Address address) {
  printf("Page Number:\t%02x\nOffset:\t\t%02x\n",
         address.page_number,
         address.offset);
}

int main() {
  Address address;
  address_init(&address, 0x11223456);
  address_print(address);
}
