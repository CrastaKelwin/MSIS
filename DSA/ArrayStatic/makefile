# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# the build target executable:
TARGET = main

SOURCES = array_static.c

all: $(TARGET)

$(TARGET): $(TARGET).c
		$(CC) -o $(TARGET) $(TARGET).c $(SOURCES)

clean:
		$(RM) $(TARGET) *.o


# all: main.c 
# 		gcc -o main main.c array_static.c

# clean: 
# 		$(RM) main