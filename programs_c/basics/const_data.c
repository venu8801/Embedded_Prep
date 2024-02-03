/* constant keyword understanding
 * */

#include <stdio.h>

int main()
{
	const int val = 0x12; // const applied to data
	
//	val = 0x56;  //resutls in error during compilation

	int *ptr = &val;

	*ptr = 0x56;  //allowed const applied to data it can be modified by a pointer

	printf("val = %x\n",val);

	return 0;
}
