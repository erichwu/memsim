#ifndef _TYPES_H
#define _TYPES_H

#include <stdint.h>

/** TLB_MISS indicates an entry is not in the TLB*/
#define TLB_MISS -1
/** PAGE_MISS indicates an entry is not in the page table*/
#define PAGE_MISS -2
/** SOMETHING_IS_WRONG unknown error (probably backing store error)*/
#define SOMETHING_IS_WRONG -3

#define FIFO 1
#define LRU 2

/** PHYSICAL_MEMORY_SIZE. */
#define PHYSICAL_MEMORY_SIZE (1 << 16)
/** PAGE_TABLE_SIZE. */
#define PAGE_TABLE_SIZE (1 << 8)
/** PAGE_SIZE. */
#define PAGE_SIZE (1 << 8)
/** FRAME SIZE. */
#define FRAME_SIZE (1 << 8)
/** PAGE_COUNT. */
#define PAGE_COUNT (PHYSICAL_MEMORY_SIZE / PAGE_SIZE)
/** FRAME_COUNT. */
#define FRAME_COUNT (PHYSICAL_MEMORY_SIZE / FRAME_SIZE)
/** LOGICAL_MEMORY_SIZE. */
#define LOGICAL_MEMORY_SIZE (FRAME_SIZE * FRAME_COUNT);
/** TLB_ENTRIES. */
#define TLB_ENTRIES 16
/** BITS_PER_BYTE. */
#define BITS_PER_BYTE 8

typedef uint8_t PageNumber;
typedef uint8_t FrameNumber;
typedef uint8_t ValidBit;
typedef uint8_t Offset;
typedef uint8_t FrameValue;
typedef unsigned char FrameBlock[FRAME_SIZE];

int tlb_misses;
int page_misses;
int total_loads;
/**
 * Address in a 16-bit format.
 *
 * Upper 8 bits are the page number and lower 8 bits are the offset.
 */
typedef struct {
  PageNumber page_number;
  Offset offset;
} Address;

#endif
