#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"
#include "stdlib.h"
#include "stdio.h"
#define BACKING_STORE_FILE "BACKING_STORE"

typedef struct {
	uint8_t table[FRAME_SIZE];
} FrameBlock;

typedef struct {
	FrameBlock* table[FRAME_COUNT]; 
	uint8_t free_frame_pointer;
	FILE* backing_store;
} PhysicalMemory;

/** Initialize Memory members*/
void memory_init(PhysicalMemory* memory);

/** Return frame number of loaded memory after loading available position */
int memory_load(PhysicalMemory* memory, Offset offset, FrameNumber* frame_number);

int memory_get(FrameNumber frame_number, Offset offset, FrameValue* frame_value);

void frame_block_init(FrameBlock* block);

#endif