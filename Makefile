SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
MAIN=memsim
INCLUDE=include

all: $(OBJECTS) $(INCLUDES)
	gcc -o $(MAIN) $(EXECUTABLE) $(OBJECTS)

.c.o:
	gcc -I $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(MAIN)
