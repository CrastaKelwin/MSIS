# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# the build target executable:
# .PHONY : all
# all: $(TARGET)

$(TARGET): $(TARGET).c
		$(CC) -o $(TARGET) $(TARGET).c

.PHONY : clean
clean:
		$(RM) $(TARGET) *.o

.PHONY : run
run: $(TARGET_RUN)
		./$(TARGET_RUN)
		$(RM) $(TARGET) *.o
