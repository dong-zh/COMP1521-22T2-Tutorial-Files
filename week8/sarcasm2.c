/**
 * @file sarcasm2.c
 * @author Dongzhu Huang
 * @brief Reads a text file and outputs a sarcastic version of it
 * @date 22T1
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <err.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	// Arg check
	if (argc != 3) {
		fprintf(stderr, "Usage %s <input filename> <output filename>\n", argv[0]);
		return EXIT_FAILURE;
	}

	FILE *inputFile = fopen(argv[1], "r");
	if (inputFile == NULL) {
		err(EXIT_FAILURE, "failed to open %s", argv[1]);
	}
	FILE *outputFile = fopen(argv[2], "w");
	if (outputFile == NULL) {
		err(EXIT_FAILURE, "failed to open %s", argv[2]);
	}

	int c;
	bool capitalise = false;
	while ((c = fgetc(inputFile)) != EOF) {
		if (capitalise) {
			c = toupper(c);
		} else {
			c = tolower(c);
		}
		capitalise = !capitalise;

		if (fputc(c, outputFile) == EOF) {
			err(EXIT_FAILURE, "failed to write %c into %s", c, argv[1]);
		}
	}
	fclose(inputFile);
	fclose(outputFile);

	return EXIT_SUCCESS;
}
