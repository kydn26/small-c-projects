#include "test_storage.h"

void test_add_line_to_file() {
  char *line = "1|Review documents|high|pending\n";
  char *filename = "test.txt";
  remove(filename);
  add_line_to_file(line, filename);
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  char buffer[100];
  fgets(buffer, sizeof(buffer), file);
  assert(strcmp(buffer, line) == 0);
  fclose(file);
  remove(filename);
}

void test_read_first_line_from_file() {
  char *lines = 
    "1|Review documents|high|pending\n"
    "2|Attend meeting with John|medium|pending\n"
    "3|Prepare presentation|low|pending\n";
  char *filename = "test.txt";
  FILE *file = fopen(filename, "w");
  if (file == NULL)
  {
    printf("Error opening file: %s\n", filename);
    return;
  }
  fprintf(file, "%s", lines);
  fclose(file);
  char *result = read_line_from_file(1, filename);
  assert(strcmp(result, "1|Review documents|high|pending\n") == 0);
  remove(filename);
}

void test_read_second_line_from_file() {
  char *lines = 
    "1|Review documents|high|pending\n"
    "2|Attend meeting with John|medium|pending\n"
    "3|Prepare presentation|low|pending\n";
  char *filename = "test.txt";
  FILE *file = fopen(filename, "w");
  if (file == NULL)
  {
    printf("Error opening file: %s\n", filename);
    return;
  }
  fprintf(file, "%s", lines);
  fclose(file);
  char *result = read_line_from_file(2, filename);
  assert(strcmp(result, "2|Attend meeting with John|medium|pending\n") == 0);
  remove(filename);
}