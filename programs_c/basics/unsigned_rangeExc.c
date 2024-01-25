/* unsigned range exceeding -ve ---- +ve values*/

#include <stdio.h>
int main()
{
	unsigned int val = 0xffffffff;  //range exceed
					 //+ve val
					 //in unsigned MSB is not considered for +ve values even if range exceeds it considers only in range 
					 //value

	printf("val : %d\n",val); // retrieving done by printf which takes care of MSB so -ve value
	int i;
	for(i =31; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}

	val = -0xfffffffff;  //-ve in unsigned range exceeding 
	printf("\nval : %d\n",val);

	for(i =31; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}
	return 0;
}


