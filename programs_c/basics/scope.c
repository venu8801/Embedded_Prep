/* understanding scope */
#include <stdio.h>
int x; // un-initialized global
int main()
{
	x = 30;
	int x = 40; // same name but in different scope /local variable/
	printf("%d\n",x); //prints 40 considers local variables first
	{
		x = 50; //modifes local x
		printf("%d\n",x); // prints 50

		int x = 60; //same name but inside blockscope 
		printf("%d\n",x); // prints 60

		
	}

	printf("%d\n",x); // prints 50
	return 0;
}
