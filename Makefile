CC=gcc
CFLAGS=-Wall -g

SRC_DIR=src
OBJ_DIR=obj

SRC=$(SRC_DIR)/thread_pool.c
OBJ=$(OBJ_DIR)/thread_pool.o

all: $(OBJ)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)/*


$(OBJ_DIR):
	if ! [ -d "./$@" ]; then mkdir $@; fi
