// Prints out a string from command line sarcastically
// Dongzhu Huang (z5257526)
// 22T2



#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	// arg check
	if (argc != 2) {
		// This should fprintf() to stderr instead
		printf("Wrong number of args\n");
		return 1;
	}

	char *original = argv[1];

	int i = 0;
	while (i < strlen(original)) {
		if (i % 2 == 0) {
			putchar(tolower(original[i]));

		} else {
			putchar(toupper(original[i]));
		}
		i++;
	}

	putchar('\n');

	return 0;
}
