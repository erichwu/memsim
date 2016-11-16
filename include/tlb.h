#ifndef _TLB_H
#define _TLB_H

#include "types.h"

#define TLB_SIZE 16

typedef struct {
	PageNumber pageNumber;
	FrameNumber frameNumber;
	ValidBit validBit;
} TLBEntry;

typedef struct {
	TLBEntry table[TLB_SIZE];
} TLB;



#endif