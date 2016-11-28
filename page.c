#include "types.h"
#include "page.h"

int page_get(Page* page_table, PageNumber page_number, FrameNumber* frame_number);

void page_init(Page* page_table); 


