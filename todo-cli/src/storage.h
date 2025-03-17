#ifndef STORAGE_H
#define STORAGE_H

#define MAX_LINE_LENGTH 1024


void add_line_to_file(char *line, char *filename);
// remove line from file
void remove_line_from_file(char *line, char *filename);
// read line from file
char *read_line_from_file(int position, char *filename);
// read all lines from file
char **read_all_lines_from_file(char *filename);
// write line to file
void write_line_to_file(char *line, char *filename);

#endif