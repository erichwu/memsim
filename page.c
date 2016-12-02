#include "types.h"
#include "page.h"
#include "stdlib.h"
#include "stdio.h"
#include "parser.h"

int page_get(Page* page_table, Address address, FrameNumber* frame_number) {
	if (page_scan(page_table, address, frame_number) == PAGE_MISS) {
		if (memory_load(page_table->main_memory, 
										address.offset, frame_number) == SOMETHING_IS_WRONG){
			printf("Error with memory caught in page_get\n");
			exit(1);
		}
		page_table->table[address.page_number] = frame_number;
		//printf("PAGE MISSED");
		page_misses++;
	}
	return 0;
}

int page_scan(Page* page_table, Address address, FrameNumber* frame_number) {
	if (page_table->table[address.page_number] != NULL) {
		frame_number = page_table->table[address.page_number];
		return 0;
	}
	return PAGE_MISS;
}

void page_init(Page** page_table, PhysicalMemory* main_memory) {
	(*page_table) = (Page*)malloc(sizeof(Page));
	int i;
	for (i = 0; i < PAGE_TABLE_SIZE; i++) {
		(*page_table)->table[i] = NULL;
		//printf("%u", i);
	}
	(*page_table)->free_entry_pointer = 0;
	(*page_table)->main_memory = main_memory;
}




