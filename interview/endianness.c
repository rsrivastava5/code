#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv) {
	union Data {
		uint8_t c[4];
		uint32_t l;
	} test = { .l = 0x01000000 };
	printf(test.c[0] ? "Big endian\n" : "Little endian\n");
		
	return 0;
}

