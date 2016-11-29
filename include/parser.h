#ifndef _PARSER_H
#define _PARSER_H

#include "types.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// All sizes are in bytes.

/** make_uint16_t by masking lower 2 bytes of address. */
Address make_address(uint32_t address);

/** page_number accessed from upper byte of address. */
PageNumber page_number(uint16_t address);

/** offset accessed from lower byte of address. */
Offset offset(uint16_t address);

/** address_init creates an Address from a 32 bit logical address. */
void address_init(Address* address, uint32_t address_32_bit);

/** address_print prints an Address. */
void address_print(Address address);

#endif
