CC := gcc
CFLAGS := -Wall -Werror
TARGET := code

.PHONY: all clean dclean

all: $(TARGET)

$(TARGET): code.c instruction.c code.h
	@echo "##########################"
	@echo "   Compiling $(TARGET)    "
	@echo "##########################"
	$(CC) $(CFLAGS) -o code code.c instruction.c -lm
	@echo

dclean: 
	@echo "##########################"
	@echo "     Cleaning all         "
	@echo "##########################"
	-rm -f $(TARGET)
	@echo


play0: all
	./code 



	
	