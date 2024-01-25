#include <stdio.h>

int main()
{

	unsigned char val = 0x78;
//   0111 1000
//   0111 1101   --->  7 D
	//set 0th bit and 2d bit
	//
	
	val = val | ( (0x1 << 2) | (0x1 << 0) );
	printf("val: %x\n",val);
	return 0;
}	
