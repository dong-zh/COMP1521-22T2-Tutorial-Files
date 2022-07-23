/**
 * @file seek.c
 * @author Dongzhu Huang
 * @brief Prints the word impostor from the innocent text file
 * @date 22T1
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define FILENAME "innocentTextFile.txt"
#define OFFSET (22)
#define WORD_LENGTH (8)

int main(void)
{
	FILE *file = fopen(FILENAME, "r");
	if (file == NULL) {
		err(EXIT_FAILURE, "Failed to open %s", FILENAME);
	}

	// Move the cursor
	if (fseek(file, -OFFSET, SEEK_END) == -1) {
		err(EXIT_FAILURE, "failed to fseek");
	}

	for (int i = 0; i < WORD_LENGTH; i++) {
		int c = fgetc(file);
		putchar(c);
	}

	fclose(file);
}
