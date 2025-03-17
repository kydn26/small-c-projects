# Variables
CC = gcc
CFLAGS = -Wall  # Compilation flags
OBJ_DIR = obj
SRC_OBJ_DIR = $(OBJ_DIR)/src
TEST_OBJ_DIR = $(OBJ_DIR)/tests
BIN_DIR = bin
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=$(SRC_OBJ_DIR)/%.o)
EXEC = $(BIN_DIR)/todo-cli

# Test files
TEST_SRC = $(wildcard tests/*.c)
TEST_OBJ = $(TEST_SRC:tests/%.c=$(TEST_OBJ_DIR)/%.o)
TEST_EXEC = $(BIN_DIR)/test_runner

all: $(EXEC) $(TEST_EXEC)

# Create directories if they don't exist
$(SRC_OBJ_DIR) $(TEST_OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Compile source files to object files
$(SRC_OBJ_DIR)/%.o: src/%.c | $(SRC_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link and generate the application executable
$(EXEC): $(OBJ) | $(BIN_DIR)
	$(CC) $(OBJ) -o $(EXEC)

# Compile test files to object files
$(TEST_OBJ_DIR)/%.o: tests/%.c | $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link and generate the test executable
$(TEST_EXEC): $(TEST_OBJ) $(OBJ:$(SRC_OBJ_DIR)/main.o=) | $(BIN_DIR)
	$(CC) $(TEST_OBJ) $(OBJ:$(SRC_OBJ_DIR)/main.o=) -o $(TEST_EXEC)

# Run tests
run_tests: $(TEST_EXEC)
	./$(TEST_EXEC)

# Clean generated files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the application
run: $(EXEC)
	./$(EXEC)
