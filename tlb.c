#include "tlb.h"
#include "types.h"
#include "parser.h"
#include "memory.h"
#include "page.h"

#include <limits.h>

int tlb_scan(TLB* tlb, Address address, FrameNumber* frame_number) {
	PageNumber search = address.page_number;
	int i;
	for (i = 0; i < TLB_ENTRIES; i++) {
		if (tlb->table[i]->page_number == search) {
			*frame_number = tlb->table[i]->frame_number; 
			tlb->table[i]->last_used = time(NULL);
			return 0;
		}
	}
	return TLB_MISS;
}

int tlb_get(TLB* tlb, Address address, int mode, FrameValue* frame_value) {
	FrameNumber frame_number;
	if (tlb_scan(tlb, address, &frame_number) == TLB_MISS) {
		page_get(tlb->page_table, address, &frame_number);
		if (mode == FIFO) {
			tlb_replace_fifo(tlb, address, frame_number);
		} else if (mode == LRU) {
			tlb_replace_lru(tlb, address, frame_number);
		} else {
			printf("Operation mode isn't available\n");
			exit(-1);
		}
		tlb_misses++;
		printf("TLB MISS\n");
		exit(-1);
	}
	//Go to memory
	if (memory_get(tlb->main_memory, frame_number, address.offset, frame_value) == SOMETHING_IS_WRONG) {
		printf("Undefined physical memory issue\n");
		exit(-1);
	}
	return 0;
}

int tlb_replace_fifo(TLB* tlb, Address address, FrameNumber frame_number) {

}

int tlb_replace_lru(TLB* tlb, Address address, FrameNumber frame_number) {
	time_t lowest_time = UINT_MAX;
	int oldest_tlb = 0;
	int i;
	for (i = 0; i < TLB_ENTRIES && tlb->table[i] != NULL; i++) {
		if (lowest_time > tlb->table[i]->last_used) {
			oldest_tlb = i;
			lowest_time = tlb->table[i]->last_used;
		}
	}
	tlb_entry_init(tlb->table[oldest_tlb], oldest_tlb, frame_number);
}

void tlb_init(TLB* tlb) {
	int i;
	for (i = 0; i < TLB_ENTRIES; i++) {
		tlb->table[i] = NULL;
	}
	memory_init(tlb->main_memory);
	page_init(tlb->page_table, tlb->main_memory);
}

void tlb_entry_init(TLBEntry* tlb_entry, PageNumber page_number, FrameNumber frame_number) {
	tlb_entry->page_number = page_number;
	tlb_entry->frame_number = frame_number;
	tlb_entry->last_used = time(NULL);
}