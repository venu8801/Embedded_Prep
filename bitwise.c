#include <stdio.h>
int main()
{

	unsigned int val = 0x12345678;


	val = ((val & (0xFF000000)) >> 24 | 
	 (val & (0x00ff0000)) >> 8 | 
	(val & (0x0000ff00)) << 8 | 
	(val & (0x000000ff)) << 24 ); 
	printf("%x\n",val);
	return 0;
}
