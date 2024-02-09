/* display bits */

#include <stdio.h>

int main()
{
	float a = 7.78;
	int *ptr = &a;
	int i;
	
	for(i = 31; i >= 0; i--){
		if( *ptr & (0x1 << i))
			printf("1");
		else
			printf("0");
	}

	return 0;
}
