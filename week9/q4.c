#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <err.h>

void chmodIfPublicWritable(char *filename);

int main(int argc, char *argv[])
{
	// arg check
	if (argc < 2) {
		fprintf(stderr, "Usage %s <file1> [file2]\n", argv[0]);
		return EXIT_FAILURE;
	}

	// argv = "./a.out" "q4.c" "q7.c" "creatFileInHome.c"
	for (int arg = 1; arg < argc; arg++) {
		chmodIfPublicWritable(argv[arg]);
	}
}

void chmodIfPublicWritable(char *filename)
{
	struct stat fileStat;
	if (stat(filename, &fileStat) == -1) {
		err(EXIT_FAILURE, "failed to state %s", filename);
	}

	mode_t oldMode = fileStat.st_mode;

	if (oldMode & S_IWOTH) {
		// Public writable
		printf("Removing public write permissions on %s...\n", filename);
		mode_t newMode = oldMode & ~S_IWOTH;
		chmod(filename, newMode);
	} else {
		printf("%s is not public writable, continuing...\n", filename);
	}
}
