#ifndef PAGE_H
#define PAGE_H

#include "types.h"

/** The Page Table Struct **/
typedef struct {
	/** Array of FrameNumbers */
	FrameNumber table[PAGE_COUNT];

} Pages;

/** Get the frame number or return PAGE_MISS*/
FrameNumber frame_get(PageNumber page_number);

/** Intialize passed in page table to null */
void pages_init(Pages* page_table); 


#endif