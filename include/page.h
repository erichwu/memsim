#ifndef PAGE_H
#define PAGE_H

#include "types.h"
#include "memory.h"

/** The Page Table Struct **/
typedef struct {
	/** Array of FrameNumbers */
	FrameNumber* table[PAGE_COUNT];
	uint8_t free_entry_pointer;
	PhysicalMemory* main_memory;
} Page;

/** Get the frame number or return PAGE_MISS*/
int page_get(Page* page_table, Address address, FrameNumber* frame_number);

int page_scan(Page* page_table, Address address, FrameNumber* frame_number);

/** Intialize passed in page table to null */
void page_init(Page** page_table, PhysicalMemory* main_memory); 


#endif