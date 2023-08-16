# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# the build target executable:
TARGET = main

SOURCES = array.c split_array.c

all: $(TARGET)

$(TARGET): $(TARGET).c
		$(CC) -o $(TARGET) $(TARGET).c $(SOURCES)

clean:
		$(RM) $(TARGET) *.o