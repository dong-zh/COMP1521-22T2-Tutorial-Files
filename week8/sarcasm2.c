/**
 * @file sarcasm2.c
 * @author Dongzhu Huang
 * @brief Reads a text file and outputs a sarcastic version of it
 * @date 22T2
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <err.h>
#include <stdbool.h>

// You don't need errno to use err()
// #include <errno.h>

// int errno;

int main(int argc, char *argv[])
{
	// arg check
	if (argc != 3) {
		// wrong number of args
		fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *inputFileName = argv[1];
	char *outputFileName = argv[2];

	// Open input file in reading mode and check for error
	FILE *inputFile = fopen(inputFileName, "r");
	if (inputFile == NULL) {
		err(EXIT_FAILURE, "failed to open %s", inputFileName);
	}

	// Open output file in writing mode and check for error
	FILE *outputFile = fopen(outputFileName, "w");
	if (outputFile == NULL) {
		err(EXIT_FAILURE, "failed to open %s", outputFileName);
	}

	int character;
	int count = 0;

	// Read until EOF
	while ((character = fgetc(inputFile)) != EOF) {
		if (count % 2 == 0) {
			character = tolower(character);
		} else {
			character = toupper(character);
		}

		fputc(character, outputFile);


		count++;
	}


	// fgetc: reads in 1 character at a time
	// fgets: reads in a whole line at a time
	// fread: reads in n bytes at a time
	// fscanf: reads in a word, an int, or a double...

	fclose(inputFile);
	fclose(outputFile);
}
