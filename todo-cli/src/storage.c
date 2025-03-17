#include "storage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_line_to_file(char *line, char *filename)
{
  FILE *file = fopen(filename, "at");
  if (file == NULL)
  {
    printf("Error opening file: %s\n", filename);
    return;
  }
  fprintf(file, "%s", line);
  fclose(file);
}

char *read_line_from_file(int position, char *filename)
{
  FILE *file = fopen(filename, "r");
  if (!file)
  {
    perror("Error al abrir el archivo");
    return NULL;
  }

  char buffer[MAX_LINE_LENGTH];
  int current_line = 1;

  while (fgets(buffer, MAX_LINE_LENGTH, file))
  {
    if (current_line == position)
    {
      fclose(file);
      char *message = (char *)malloc(strlen(buffer) + 1);
      strcpy(message, buffer);
      return message;
    }
    current_line++;
  }

  printf("No se encontró la línea %d en el archivo.\n", position);
  fclose(file);
  return NULL;
}