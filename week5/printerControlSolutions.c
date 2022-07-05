#include <stdio.h>
#include <stdint.h>

#define NO_INK (0x1)
#define COLOUR (0x2)
#define SELECT_PRINT (0x4)
#define SELECT_SCAN (0x8)
#define START (0x10)

// The printer
uint8_t printerControl = 0b0000000;

void checkInk(void);
void replaceInk(void);
void useColourAndSelectScan(void);
void toggleMode(void);
void start(void);

int main(void)
{
	// Main function for testing
	printf("printerControl = 0x%02x\n", printerControl);
	// checkInk();
	// replaceInk();
	// useColourAndSelectScan();
	// start();
	// toggleMode();
	printf("printerControl = 0x%02x\n", printerControl);

}

void checkInk(void)
{
	if (printerControl & NO_INK) {
		printf("Out of ink\n");
	} else {
		printf("Ink levels OK\n");
	}
}

void replaceInk(void)
{
	// Assume the user has replaced the ink
	printerControl &= ~NO_INK;
}

void useColourAndSelectScan(void)
{
	// Assume no mode has been selected yet
	printerControl |= (SELECT_SCAN | COLOUR);
}

void toggleMode(void)
{
	// Assume 1 mode has been selected
	printerControl ^= (SELECT_SCAN | SELECT_PRINT);
}

void start(void)
{
	// Check that only 1 mode is selected
	// Double bang to boolean-ise our bitwise results
	int scanSelected = !!(printerControl & SELECT_SCAN);
	int printSelected = !!(printerControl & SELECT_PRINT);

	if (scanSelected == printSelected) {
		printf("Invalid mode\n");
		return;
	}

	if (printSelected) {
		if (printerControl & NO_INK) {
			printf("Trying to print, but no ink\n");
			return;
		}

		printf(
			"Printing in %s\n",
			((printerControl & COLOUR) ? "colour" : "black and white")
		);
	} else {
		printf(
			"Scanning in %s\n",
			((printerControl & COLOUR) ? "colour" : "black and white")
		);

	}

	// Start the task
	printerControl |= START;

	// The code below is part of question 5.4, and wasn't done in the tutorial
	while (printerControl & START) {
		// Infinite loop until the printer unsets the start bit
		// In our code, this will never finish because we don't have a real printer on the other side telling us when it's done
	}

	printf("Done!\n");
}
