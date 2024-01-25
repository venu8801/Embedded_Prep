
#include <stdio.h>

int main()
{

	unsigned char val = 0x78;
//   0111 1000
//   0111 1101   --->  7 D
	//clear 3rd bit so o/p become 0x70
	//
	
	val = val & ~( 0x1 << 3 );
	printf("val: %x\n",val);
	return 0;
}	
