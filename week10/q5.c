#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *sayHello(void *arg)
{
	char *name = (void *)arg;
	printf("Hello, %s!\n", name);
	sleep(1);
	return "This is a return value";
}

int main(void)
{
	pthread_t myThread;
	pthread_create(&myThread, NULL, sayHello, "Dong");

	// sayHello("Dong");
	char *retVal;
	printf("Waiting for thread...\n");

	// Wait for myThread to finish
	pthread_join(myThread, (void *)&retVal);

	printf("Thread returned %s\n", retVal);
}
