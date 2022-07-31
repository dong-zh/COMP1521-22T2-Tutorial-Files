#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <err.h>
#include <errno.h>

extern char **environ;

void spawnAndWait(char *argv[]);

int main(void)
{
	char **tasks[5];
	tasks[0] = (char *[]){"/bin/date", "+%d-%m-%Y", NULL};
	tasks[1] = (char *[]){"/bin/date", "+%T", NULL};
	tasks[2] = (char *[]){"/usr/bin/whoami", NULL};
	tasks[3] = (char *[]){"/bin/hostname", "-f", NULL};
	tasks[4] = (char *[]){"/usr/bin/realpath", ".", NULL};

	for (int i = 0; i < 5; i++) {
		spawnAndWait(tasks[i]);
	}

	return 0;
}

void spawnAndWait(char *argv[])
{
	pid_t pid;

	// Do the spawn
	printf("spawning %s\n", argv[0]);
	int error = posix_spawn(&pid, argv[0], NULL, NULL, argv, environ);

	if (error != 0) {
		errno = error;
		err(1, "posix_spawn() failed");
	}

	int exitCode;
	printf("waiting for %s to finish\n", argv[0]);
	if (waitpid(pid, &exitCode, 0) == -1) {
		err(1, "waitpid() failed");
	}
}
