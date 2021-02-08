CC = gcc
CFLAGS = -O
TARGET = final_project.out
OBJECTS =  avl_search.o bst_search.o linear_search.o common.o mnemonic.o main.o

all : $(TARGET)

.PHONY: clean

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	$(MAKE) clean
clean :
	rm *.o