#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

typedef struct {
	FrameBlock table[FRAME_COUNT]; 
	uint8_t free_frame_pointer;
} PhysicalMemory;

/** Initialize Memory members*/
void memory_init(PhysicalMemory* memory);

/** Return frame number of loaded memory after loading available position */
int memory_load(Offset offset, FrameNumber* frame_number);

int memory_get(FrameNumber frame_number, Offset offset, FrameValue* frame_value);

#endif