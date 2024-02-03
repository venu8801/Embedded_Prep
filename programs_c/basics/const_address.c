/* const keyword applied to address */



#include <stdio.h>

int main()
{
	int val = 0x67;
	int b;
	const int * const ptr = &val;  // const applied to pointer now this pointer points to only one var 
			    // and cannot point any other var 
//	ptr = NULL;
//	*ptr = 89; //cannot modify data using that pointer  
//	ptr = &b; //cannot modify pointer also 

	val = 0x78; //data at the var can be directly modified 	directly using var's name
	printf("val : %x\n",val);

	return 0;

}
