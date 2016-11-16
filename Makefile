SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
MAIN=msim
INCLUDE=include

all: $(OBJECTS)
	gcc -o $(MAIN) $(EXECUTABLE) $(OBJECTS)

.c.o:
	gcc -I $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(MAIN)
