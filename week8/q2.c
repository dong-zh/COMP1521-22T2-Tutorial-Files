#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define MAX_LINE (65535)

void searchFile(FILE *file, char fileName[], char target[]);

int main(int argc, char *argv[])
{
	// arg check
	if (argc < 2) {
		fprintf(stderr, "Usage %s: <target> <file 1> [file 2]\n", argv[0]);
		return EXIT_FAILURE;
	}

	// target is the word of phrase we're looking for
	char *target = argv[1];
	// argv == "./fgrep" "bee" "amogus.txt" "bee-movie.txt"
	if (argc == 2) {
		// Look for target from stdin (terminal)
		searchFile(stdin, "stdin", target);
	} else {
		// Look for target in all the given files
		for (int arg = 2; arg < argc; arg++) {
			// Open the file in reading mode and check for error
			FILE *file = fopen(argv[arg], "r");
			if (file == NULL) {
				err(EXIT_FAILURE, "failed to open %s", argv[arg]);
			}

			searchFile(file, argv[arg], target);

			fclose(file);
		}
	}
}

void searchFile(FILE *file, char fileName[], char target[])
{
	// fgetc: reads in 1 character at a time
	// fgets: reads in a whole line at a time
	// fread: reads in n bytes at a time
	// fscanf: reads in a word, an int, or a double...

	char lineBuffer[MAX_LINE];
	int lineNumber = 1;
	// Loop through every line in the file
	while (fgets(lineBuffer, MAX_LINE, file) != NULL) {
		// Check whether our target is in this particular line
		if (strstr(lineBuffer, target) != NULL) {
			// if strstr() returns NULL, it means the target is in this line, so print the line
			printf("%s:%d:%s", fileName, lineNumber, lineBuffer);
		}

		lineNumber++;
	}
}
