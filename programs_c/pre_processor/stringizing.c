/* stringizing operator */

#include <stdio.h>

#define PRNT(VAL) printf("VAL : %s\n",VAL)

#define PRNT_STR(VAL) printf(#VAL " : %s\n",VAL)  //#VAL is used instead of VAL this replaces the actual variable name
						  //
						  //#VAL will stringize 
int main()
{
	char str[] = "venu";

	PRNT(str); // prints VAL : venu
		   // the value inside string is not replaced 

	PRNT_STR(str);  //prints str : venu

	return 0;
}
