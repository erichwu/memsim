#ifndef PAGE_H
#define PAGE_H

#include "types.h"

/** The Page Table Struct **/
typedef struct {
	/** Array of FrameNumbers */
	FrameNumber table[PAGE_COUNT];
	uint8_t free_entry_pointer;
} Page;

/** Get the frame number or return PAGE_MISS*/
int page_get(Page* page_table, PageNumber page_number, FrameNumber* frame_number);

/** Intialize passed in page table to null */
void page_init(Page* page_table); 


#endif