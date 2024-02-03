/* difference b/w \
 * \
 *
 *
 * | const int *ptr |  and |   int * const ptr |
 *
 *| const int *ptr | ----> const applied data pointed by pointer  *ptr =  not possible
 *
 *|   int * const ptr |------> const applied to address pointer can only point one address ptr = change not possible
 */


#include <stdio.h>
int main()
{
	int val = 0x33;
	int b;
	const int*  ptr = &val;  // const applied to data pointed by pointer
	
	 int * const valPTR = &val; // const applied to address not data

//	 valPTR = NULL; //error
			//
	*valPTR = 0x55;

//	ptr = &b;  // pointer can point other vars
//	ptr = NULL; //pointer can be modified
	
//	*ptr = 0x34; // data cannot be changed results in compilation error


	//-------------//
	//taking other pointer to point to val and trying to modify data inside val
	
	int *val_ptr = &val;

	*val_ptr = 0x66;
	return 0;
}
