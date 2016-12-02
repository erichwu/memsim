#ifndef PAGE_H
#define PAGE_H

#include "types.h"
#include "memory.h"

/** The Page Table Struct **/
typedef struct {
	/** Array of FrameNumbers */
	FrameNumber* table[PAGE_COUNT];
	/** The first free entry pointer*/
	uint8_t free_entry_pointer;
	/** A reference to the physical memory*/
	PhysicalMemory* main_memory;
} Page;

/** Get the frame number or return PAGE_MISS*/
int page_get(Page* page_table, Address address, FrameNumber* frame_number);

/** Check if a page number has a frame number and return it if so*/
int page_scan(Page* page_table, Address address, FrameNumber* frame_number);

/** Intialize passed in page table to null */
void page_init(Page** page_table, PhysicalMemory* main_memory); 


#endif