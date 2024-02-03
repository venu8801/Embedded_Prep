/* program to multiply two numbers without using
 * arithmetic operators */

#include <stdio.h>

int BitwiseMUL(int a, int b)
{
	int result = 0;
	while(b > 0)
	{
		if(b & 1) //first check if b is even or odd
		{
			result += a;	

		}

		a = a << 1; // multiply by 2
		b = b >> 1; //divide by 2




	}

	return result;
}

int main()
{
	printf("Mul: %d\n",BitwiseMUL(5,3));

	return 0;
}
