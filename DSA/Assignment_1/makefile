# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# the build target executable:
TARGET = main

# Add all source files
SOURCES = seat_allotment.c

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) -o $(TARGET) $(TARGET).c $(SOURCES)

clean:
	$(RM) $(TARGET) *.o

run_tests: $(TARGET)
	./$(TARGET)
	make clean
