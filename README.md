# COMP 3500 Virtual Memory Manager

* Group 9: Will O., Cameron S., Erich W.

## Usage: Making/Running

This code satisfies the requirement of separate compilation. 

* To compile: `make`
* To run: `./memsim`
* To delete object files and executables `make clean`
* To print output in console simply type `yes` when prompted by the program.
* To run in LRU, FIFO, or other future modes simply type in the correct corresponding number as shown by the menu.

### Other options: 

* To change the input or output file, change the defines of `TEST_FILE` and `OUTPUT_FILE` in `main.c`. Don't forget to `make`.
* To change system values change define values in `include/types.h`. You will have to `make clean` then `make`.



