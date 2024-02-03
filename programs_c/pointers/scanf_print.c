/* scanf using pointer */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr;  // wild pointer
	printf("Enter a num: ");
	scanf("%d",ptr); // accessing a invalid address results in SIGSEGV
	printf("%d\n",*ptr);
	return 0;


}
