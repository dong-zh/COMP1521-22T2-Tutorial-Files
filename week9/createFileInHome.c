/**
 * @file createFileInHome.c
 * @author Dongzhu Huang (z5257526)
 * @brief Create a file with the argument as the filename in the home directory.
 * @date 22T1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>


int main(int argc, char *argv[])
{
	// arg check
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
		return EXIT_FAILURE;
	}
	char *homePath = getenv("HOME");
	if (homePath == NULL) {
		fprintf(stderr, "can't get $HOME\n");
		return EXIT_FAILURE;
	}
	// homePath = "/home/dong"
	// argv[1] = "hello.txt"
	// "/home/dong/hello.txt"
	// printf("%s/%s\n", homePath, argv[1]);

	// +1 for the slash, +1 for the null
	int pathLength = strlen(homePath) + strlen(argv[1]) + 2;
	char fullPath[pathLength];
	// Constructing the full path
	snprintf(fullPath, pathLength, "%s/%s\n", homePath, argv[1]);

	// Open and create the file, and check error
	FILE *file = fopen(fullPath, "w");
	if (file == NULL) {
		err(EXIT_FAILURE, "failed to open %s", fullPath);
	}

	// Print hello into the file
	fprintf(file, "Hello file!\n");
	fclose(file);
}
