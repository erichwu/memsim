#include "tlb.h"
#include "types.h"
#include "parser.h"
#include "memory.h"

int tlb_scan(TLB* tlb, Address address, FrameNumber* frame_number) {
	PageNumber search = address.page_number;
	int i;
	for (i = 0; i < TLB_ENTRIES; i++) {
		if (tlb->table[i]->page_number == search) {
			*frame_number = tlb->table[i]->frame_number; 
			return 0;
		}
	}
	return TLB_MISS;
}

int tlb_get(TLB* tlb, Address address, int mode, FrameValue* frame_value) {
	FrameNumber frame_number;
	if (tlb_scan(tlb, address, &frame_number) == TLB_MISS) {
		/**
		* Go to page table to get entry
		* Call replacement strategy
		*/
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
	if (memory_get(frame_number, address.offset, frame_value) == SOMETHING_IS_WRONG) {
		printf("Undefined physical memory issue\n");
		exit(-1);
	}
	return 0;
}

int tlb_replace_fifo(TLB* tlb, Address address, FrameNumber frame_number) {

}

int tlb_replace_lru(TLB* tlb, Address address, FrameNumber frame_number) {

}

void tlb_init(TLB* tlb) {
	int i;
	for (i = 0; i < TLB_ENTRIES; i++) {
		tlb->table[i] = NULL;
	}
}