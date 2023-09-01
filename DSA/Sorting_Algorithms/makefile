CC := gcc

TARGET := main

SOURCES := BubbleSort/bubble_sort.c SelectionSort/selection_sort.c InsertionSort/insertion_sort.c

INCLUDES := -IBubbleSort/ -ISelectionSort/ -IInsertionSort/

CFLAGS:= -Wall -Werror -g -O0 -std=c99

.PHONY: all clean

all:$(TARGET)

$(TARGET):$(TARGET).c
	$(CC) -o $(TARGET) $(TARGET).c $(CFLAGS) $(INCLUDES) $(SOURCES)

clean:
	rm $(TARGET) *.o