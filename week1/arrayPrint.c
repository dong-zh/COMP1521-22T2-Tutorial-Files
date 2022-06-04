// Prints 10 numbers in an array
// 22T2
// Dongzhu Huang

#include <stdio.h>
#include <err.h>

#define ARRAY_LENGTH (10)

void printArrayI(int array[], int length);
void printArrayR(int array[], int indexToPrint, int length);

int main(void)
{
	// Numbers to add up
	int numbers[ARRAY_LENGTH] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

	printArrayR(numbers, 0, ARRAY_LENGTH);

	return 0;
}

// TODO
void printArrayR(int array[], int indexToPrint, int length)
{
	// Terminating case
	if (indexToPrint >= length) {
		return;
	}

	// Recursive call
	// Increment index
	printArrayR(array, indexToPrint + 1, length);

	// Doing the print after the recursive call makes it print backwards

	// Do work
	printf("Index: %d, value: %d\n", indexToPrint, array[indexToPrint]);
}

/**
 * @brief Prints an array
 *
 * @param array the array to print
 * @param length the length of the array
 */
void printArrayI(int array[], int length)
{
	for (int i = 0; i < length; i++) {
		printf("%d\n", array[i]);
	}
}
