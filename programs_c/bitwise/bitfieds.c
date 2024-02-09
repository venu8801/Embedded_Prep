
/* bit fields is collection of adjacent bits in a memory location
 * bit fields can only declared inside a structure */
#include <stdio.h>

struct dob{

	unsigned int dd:5;
	unsigned int mm:4;
	unsigned int yyyy:7;

};


int main()
{
	printf("sizeof:%ld\n",sizeof(struct dob));
	struct dob venus;
	venus.dd = 15;
	venus.mm = 7;
	venus.yyyy = 1;
	int i;	
	short int *ptr = &venus;
	printf("%hi\n",*ptr);
	for(i = 15; i >= 0; i--)
	{
		if(  (*ptr) & (0x1 << i) )
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	printf("%d %d %d\n",venus.dd,venus.mm,venus.yyyy);


	return 0;
}
