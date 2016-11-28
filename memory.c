#include "types.h"
#include "memory.h"

/** Initialize Memory members*/
void memory_init(PhysicalMemory* memory);

/** Return frame number of loaded memory after loading available position */
int memory_load(Offset offset, FrameNumber* frame_number);

int memory_get(FrameNumber frame_number, Offset offset, FrameValue* frame_value);