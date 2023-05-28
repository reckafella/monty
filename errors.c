#include "monty.h"

/**
 * usage_error - error raised if the number of arguments is
 * not equal to 2
*/
void usage_error(void)
{
	fprintf(stderr, "Usage: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_io_error - error when opening files
 * @filename: file to open
*/
void file_io_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
