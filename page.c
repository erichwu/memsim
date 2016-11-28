#include "types.h"
#include "page.h"
#include "stdlib.h"
#include "stdio.h"

int page_get(Page* page_table, Address address, FrameNumber* frame_number) {
	if (page_scan(page_table, address, frame_number) == PAGE_MISS) {
		/*Call memory_load here with offset*/
	}
	return 0;
}

int page_scan(Page* page_table, Address address, FrameNumber* frame_number) {
	int i;
	if (page_table->table[address.page_number] != NULL) {
		*frame_number = page_table->table[i]->frame_number;
		return 0;
	}
	return PAGE_MISS;
}

void page_init(Page* page_table) {
	int i;
	for (i = 0; i < PAGE_TABLE_SIZE; i++) {
		page_table->table[i] = NULL;
	}
	page_table->free_entry_pointer = 0;
}




