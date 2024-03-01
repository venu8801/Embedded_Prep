/* program to check endianness of a system */

#include <stdio.h>

int main()
{
	unsigned int val = 0x12345678; // 32 bit integer unsigned
	unsigned char x = (char)val;
	char *ptr = &val;
	if(x == *ptr)
		printf("Little Endian\n");
	else
		printf("Big Endian");
	return 0;
}
