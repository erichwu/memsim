#include "types.h"
#include "page.h"
#include "stdlib.h"
#include "stdio.h"
#include "parser.h"

int page_get(Page* page_table, Address address, FrameNumber* frame_number) {
	printf("Page get called\n");
	if (page_scan(page_table, address, frame_number) == PAGE_MISS) {
		memory_load(page_table->main_memory, address.offset, frame_number);
		page_misses++;
	}
	printf("Page get finished\n");
	return 0;
}

int page_scan(Page* page_table, Address address, FrameNumber* frame_number) {
	printf("address %p\n", &address);
	printf("offset: %u\n", address.offset);
	printf("page number: %u\n", address.page_number);
	printf("Page scan called with address %u, %u\n", address.page_number, address.offset);
	//printf("%p", page_table->table[0]);
	printf("here1\n");
	if (&page_table->table[address.page_number] != NULL) {
		printf("here2\n");
		frame_number = page_table->table[address.page_number];
		return 0;
	}
	printf("Page scan finished\n");
	return PAGE_MISS;
}

void page_init(Page* page_table, PhysicalMemory* main_memory) {
	printf("Started page_init\n");
	page_table = malloc(sizeof(Page));
	int i;
	for (i = 0; i < PAGE_TABLE_SIZE; i++) {
		page_table->table[i] = malloc(sizeof(FrameNumber));
		page_table->table[i] = NULL;
		//printf("%u", i);
	}
	page_table->free_entry_pointer = 0;
	page_table->main_memory = main_memory;
	printf("Finished page_init\n");
}




