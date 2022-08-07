#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <err.h>
#include <stdlib.h>

void *sayHello(void *arg)
{
	while (1) {
		printf("Hello\n");
		sleep(1);
	}

	return NULL;
}

int main(void)
{
	pthread_t myThread;
	if (pthread_create(&myThread, NULL, sayHello, NULL) != 0) {
		err(EXIT_FAILURE, "pthread_create failed");
	}
	while (1) {
		printf("World\n");
		sleep(1);
	}
}
