#include "test_storage.h"
#include <stdio.h>

typedef void (*runnable_test)(void);
void run_test(runnable_test func_test, char *name);
void run_tests();

void run_test(runnable_test func_test, char *name) {
  printf("Running test: %s...\n", name);
  func_test();
  printf("Test %s passed!\n", name);
}

int main() {
  printf("Running tests...\n");

  run_tests();

  printf("All tests passed!\n");
  
  return 0;
}

void run_tests() {
  run_test(test_add_line_to_file, "test_add_line_to_file");
  run_test(test_read_first_line_from_file, "test_read_first_line_from_file");
  run_test(test_read_second_line_from_file, "test_read_second_line_from_file");
}