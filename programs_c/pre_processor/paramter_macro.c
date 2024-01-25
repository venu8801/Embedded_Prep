#include <stdio.h>
#define SWAP(A,B) int temp; temp = A, A = B, B = temp

int main()
{
	int x, y;

	x = 5,  y = 9;

	SWAP(x,y);

	printf("x :%d\ty=%d\n",x,y);

	return 0;
}
