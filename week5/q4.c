#define READING (0x1)
#define WRITING (0x2)
#define AS_BYTES (0x4)
#define AS_BLOCKS (0x8)
#define LOCKED (0x10)

int main(void)
{
	unsigned char device;

	// a: locked for reading bytes
	device = READING | AS_BYTES | LOCKED;
	// c: locked while leaving other flags unchanged
	device |= LOCKED;
	// e: switch from reading to writing, leaving others unchanged
	device = (device & ~READING) | WRITING;
	// f: swap between reading and writing, leaving others unchanged
	device ^= READING | WRITING;
}
