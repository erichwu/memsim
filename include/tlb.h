#ifndef _TLB_H
#define _TLB_H

#include "types.h"
#include "memory.h"
#include "page.h"

#include <stdio.h>
#include <time.h>


/**
	* TLBEntry within the TLB table.
	* Has a page_number, frame_number, and valid_bit members
	* Has a last_used timestamp member for LRU replacement strategy.
	*
	*/
typedef struct {
	/** The page number of the TLB entry*/
	PageNumber page_number;
	/** The frame number of an entry*/
	FrameNumber frame_number;
	/** Unused valid bit for processes to check if it's read/writeable*/
	ValidBit valid_bit;
	/** Implementation detail for LRU*/
	int last_used;
} TLBEntry;

/**
	* TLB is the table that holds TLB Entries
	* Has a main_memory and page_table members to handle TLB misses and Page faults
	* Has a pointer to track the oldest insert or "first-in" element for the FIFO 
	* strategy.
	*/
typedef struct {
	/** Table of TLB entries*/
	TLBEntry* table[TLB_ENTRIES];
	/** Reference to physical memory for memory calls*/
	PhysicalMemory* main_memory;
	/** Reference to page_table for page calls*/
	Page* page_table;
	/** Modded index to determine the index of the oldest inserted entry*/
	int first_in;
} TLB;

/** Initialize TLB members*/
void tlb_init(TLB** tlb);

/** Scan for a particular page number in the TLB, return FrameNumber in frame_number parameter*/
int tlb_scan(TLB* tlb, Address address, FrameNumber* frame_number);

/** 
	* Get a particular frame value and frame number from a address. Handles faults. 
  * Returns value in frame_value parameter
  */
int tlb_get(TLB* tlb, Address address, int mode, FrameNumber* frame_number, FrameValue* frame_value);

/**
	* Replace an entry in the TLB using the FIFO strategy.
	* Uses a modulo and incrementing pointer to replace the correct value.
	*/
int tlb_replace_fifo(TLB* tlb, Address address, FrameNumber frame_number);

/**
	* Replace an entry in the TLB using the LRU strategy.
	* Uses the last_used timestamp in the TLBEntry to determine
	* the most recently used TLBEntry.
	*/
int tlb_replace_lru(TLB* tlb, Address address, FrameNumber frame_number);

/** Initialize a TLBEntry with a provided page_number and frame_number*/
void tlb_entry_init(TLBEntry** tlb_entry, PageNumber page_number, FrameNumber frame_number);

#endif
