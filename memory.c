#include "types.h"
#include "memory.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void frame_block_init(FrameBlock* block) {
	int i;
	for (i = 0; i < FRAME_SIZE; i++) {
		block->table[i] = NULL;
	}
}

/** Initialize Memory members*/
void memory_init(PhysicalMemory* memory) {
	memory->backing_store = fopen(BACKING_STORE_FILE, "r");
	int i;
	for (i = 0; i < FRAME_COUNT; i++) {
		memory->table[i] = NULL;
	}
}

/** Return frame number of loaded memory after loading available position */
int memory_load(PhysicalMemory* memory, Offset offset, FrameNumber* frame_number) {
	if (lseek(memory->backing_store, offset, SEEK_SET) == -1) {
		return SOMETHING_IS_WRONG;
	}
	char* byte;
	if (fread(byte, FRAME_SIZE, 1, memory->backing_store) != FRAME_SIZE) {
		return SOMETHING_IS_WRONG;
	}
	int i;
	for (i = 0; i < FRAME_COUNT; i++) {
		if (memory->table[i] != NULL) break;
	}
	*frame_number = i;
	FrameBlock* block = malloc(sizeof(FrameBlock));
	frame_block_init(block);
	for (i = 0; i < FRAME_SIZE; i++) {
		block->table[i] = atoi(byte[i]);
	}
	memory->table[*frame_number] = block;
	return 0;
}

int memory_get(FrameNumber frame_number, Offset offset, FrameValue* frame_value) {
	
}