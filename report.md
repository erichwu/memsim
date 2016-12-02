# Project Report

## Solution Description
1. We guarantee that each logical address is translated to the correct physical
   address by splitting our address type into two portions, upper and lower. The
   lower portion remains the same as the offset whereas the upper potion is
   converted from a page to a frame via page table lookup, with fault handling
   when necessary.

2. The TLB in our project is implemented as an array of pages/frames, with 2
   alternate replacement functions that are chosen at runtime when prompting the
   user. The TLB points to both the physical memory and page table for data flow
   purposes. The physical memory contains an array of frame blocks each of which
   contain an array of single bytes. Our page table is also a simple array of
   pages/frames.

3. We think our program realistically simulates a virtual memeory system, as it
   only references the page table on a TLB miss and only loads frames from the
   backing store on a page fault.

4. Yes (via casting and shifting)

5. The entry that gets replaced on a TLB miss depends upon the replacement
   method chosen at runtime. We implemented 2 options, FIFO and LRU. Our
   implementations of these strategies do not differ at all from the generic
   versions discussed in class.

## Generality and Performance Criteria
1. Our solution is very general as we have defined as constants in types.h the
   physical memory size, page table size, page size, frame size, page count
   frame count, logical memory size, number of TLB entries, and even the number
   of bits per byte, if that were ever to change by some breakthrough in the
   future.

2. Very because TLB size is defined as a constant in types.h

3. Yes. This amortizes the performance of loading pages across multiple calls
   instead of all at once or happening more often than necessary.

4. Yes, because virtual addresses are originally given in 32 bits and are
   eventually converted into 8 bit frame numbers and 8 bit offsets.

## Miscellaneous Factors
1. We think so because we used separate compilation, function oriented
   programming, well defined error codes, constants in a single header
   file, and short functions with a single responsibility.

2. Our approach does not try to break new grounds but rather ensures robust
   reliability.

3. We used no outside resources except the project description given in class.
