
#define PRNT1(message) printf("message")
#define PRNT2(message) printf(#message)
#include<stdio.h>
int main()
{
	char str[] = "hello world";
	PRNT2(str);
	printf("\n");
	PRNT2("hello venu");

	return 0;
}

