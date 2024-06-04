CC := gcc
CFLAGS := -Wall -Werror
TARGET := code

.PHONY: all dclean

all: $(TARGET)

$(TARGET): code.c code.h instruction.c
	@echo "##########################"
	@echo "   Compiling $(TARGET)    "
	@echo "##########################"
	$(CC) $(CFLAGS) -o code instruction.c code.c
	@echo

dclean:
	@echo "##########################"
	@echo "     Cleaning all         "
	@echo "##########################"
	-rm -f code
	@echo