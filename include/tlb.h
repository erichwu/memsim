#ifndef _TLB_H
#define _TLB_H

#include "types.h"

#include <stdio.h>
#include <time.h>


typedef struct {
	PageNumber page_number;
	FrameNumber frame_number;
	ValidBit valid_bit;
	time_t last_used;
} TLBEntry;

typedef struct {
	TLBEntry table[TLB_ENTRIES];
} TLB;






#endif
