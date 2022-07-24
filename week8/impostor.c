/**
 * @file impostor.c
 * @author Dongzhu Huang
 * @brief Prints the word impostor from the amogus file
 * @date 22T2
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define FILE_NAME ("amogus.txt")
#define OFFSET (-22)
#define WORD_LENGTH (8)

int main(void)
{
	// Open the file in reading mode
	FILE *file = fopen(FILE_NAME, "r");
	// Opening a file in reading mode puts our cursor at the start of the file

	// Check for error
	if (file == NULL) {
		err(EXIT_FAILURE, "failed to open %s", FILE_NAME);
	}
	// Move the cursor to -22 bytes from the end of file
	fseek(file, OFFSET, SEEK_END);

	// Read 8 bytes and write to stdout
	for (int count = 0; count < WORD_LENGTH; count++) {
		int character = fgetc(file);
		fputc(character, stdout);
	}

	// Close the file
	fclose(file);
}
