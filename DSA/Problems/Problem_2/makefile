CC := gcc

TARGET := main

SOURCES := dating_site.c

INCLUDES := -I..

.PHONY: clean all

clean:
	rm *.o

all:$(TARGET).c
	$(CC) -o $(TARGET).o $(TARGET).c $(SOURCES)