#ifndef _TYPES_H
#define _TYPES_H

#include "stdint.h"

#define TLB_MISS -1
#define PAGE_MISS -2
#define SOMETHING_IS_WRONG -3

typedef uint8_t PageNumber;
typedef uint8_t FrameNumber;
typedef uint8_t ValidBit;
typedef uint8_t Offset;

#endif
