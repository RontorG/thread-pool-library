CC=gcc
CFLAGS=-Wall -g

SRC_DIR=src
OBJ_DIR=obj
TEST_DIR=test
TEST_BIN_DIR=$(TEST_DIR)/bin

SRC=$(SRC_DIR)/thread_pool.c
TEST=$(TEST_DIR)/test.c

OBJ=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
TEST_BIN=$(patsubst $(TEST_DIR)/%.c,$(TEST_BIN_DIR)/%,$(TEST))

all: $(OBJ)

test: $(TEST_BIN)
	./$(TEST_BIN)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c $(OBJ) $(TEST_BIN_DIR)
	$(CC) $(CFLAGS) -I $(SRC_DIR) $< $(OBJ) -o $@
	

clean: $(BIN_DIR) $(OBJ_DIR) $(TEST_BIN_DIR)
	rm $(OBJ_DIR)/*
	rm $(TEST_BIN_DIR)/*


$(OBJ_DIR):
	if ! [ -d "./$@" ]; then mkdir -p $@; fi


$(TEST_BIN_DIR):
	if ! [ -d "./$@" ]; then mkdir -p $@; fi
