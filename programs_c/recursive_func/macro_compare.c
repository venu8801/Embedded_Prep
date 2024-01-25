/* program to write a macro to compare given inputs to macro */

#include<stdio.h>
#define COMPARE(X,Y,Z) (X > Y ? ( (X > Z) ? X: Z ) : (Y > Z)? Y: Z)

int main()
{
	int z = COMPARE(8,2,3);
	printf("greatest: %d\n",z);



	return 0;
}
