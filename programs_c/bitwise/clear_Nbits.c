/* program to clear n bits starting at p
 */

#include <stdio.h>

unsigned int clear_Nbits(unsigned int num, int n, int p)
{
	//let position be indexed from 0
	int i = 0;
	while(i < n)
	{
		num = num & ~(0x1 << p);

		p++;
		i++;
	}
	return num;
}

int main()
{
	unsigned int num = 0xffffffff;
	int pos = 24,  n = 8;

	num  = clear_Nbits(num, n, pos);


	printf("Num: %x\n",num);

}
