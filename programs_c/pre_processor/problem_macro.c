/* macro does not do any type checking */
#include <stdio.h>

//#define EX

#ifdef EX
#define MUL(X,Y) X * Y; //1
#else
#define MUL(X,Y) X * Y 
#endif

int main()
{

#ifdef EX
	int mul = MUL(2,4)
	printf("mul : %d\n",mul);
#else
	printf("product: %d\n",MUL(2+3,3+2));  // this is expanded as 2+3 * 3+2 
#endif				       // due to precedence of * 3*3 evaluates first and 2+9+2 will be result 
	// prints 13 but we are expecting 10

	return 0;
}
