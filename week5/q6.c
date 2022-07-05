#include <stdio.h>
#include <stdlib.h>


typedef unsigned int Word;
#define WORD_WIDTH (sizeof(Word) * 8)

Word reverseBits(Word input);

int main(int argc, char **argv)
{
	// Argument check
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <input number>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Convert command line argument to integer
	Word input;
	input = strtol(argv[1], NULL, 0);
	printf("Input is 0x%x\n", input);

	// Reverse the bits
	Word answer = reverseBits(input);

	// Print the answer
	printf("Answer is 0x%x\n", answer);

	return EXIT_SUCCESS;
}


Word reverseBits(Word input)
{
	Word answer = 0;
	for (int i = 0; i < WORD_WIDTH; i++) {
		answer = answer << 1;
		answer |= input & 1;
		input = input >> 1;
	}

	return answer;
}
