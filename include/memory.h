#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"
#include "stdlib.h"
#include "stdio.h"
#define BACKING_STORE_FILE "BACKING_STORE"

/** The contents of a single "frame"*/
typedef struct {
	uint8_t* table[FRAME_SIZE];
} FrameBlock;

/** The physical memory which stores our blocks of data*/
typedef struct {
	FrameBlock* table[FRAME_COUNT]; 
	uint8_t free_frame_pointer;
	int backing_store_fd;
	FILE* backing_store_pointer;
} PhysicalMemory;

/** Initialize Memory members*/
void memory_init(PhysicalMemory** memory);

/** Return frame number of loaded memory after loading available position */
int memory_load(PhysicalMemory* memory, Offset offset, FrameNumber* frame_number);

/**  Get a value of a frame number with an offset*/
int memory_get(PhysicalMemory* memory, FrameNumber frame_number, Offset offset, FrameValue* frame_value);

/** Initialize a frame block*/
void frame_block_init(FrameBlock** block);

#endif