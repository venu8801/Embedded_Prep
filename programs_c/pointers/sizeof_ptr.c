/* implement sizeof without using sizeof() operator use pointer arithmetic */

#include <stdio.h>

#define SIZE_OF(VAR) (char *)(VAR + 1) - (char *)VAR

int main(){
	long double  val = 45; 

	printf("size of long double: %ld\n",SIZE_OF(&val));
	return 0;
}
