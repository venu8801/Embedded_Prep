#include <stdio.h>
void call_back(char *str, int (*ptr)(const char*,...));

int main()
{
	void *fptr = printf; //storing printf address at fptr

	
	(( int(*)(const char *,...))fptr)("Hello all\n"); //type casting void pointer to type of printf and calling it
	
	call_back("Venu Gopal A",printf);
	return 0;
}

//callback function 
//passing a function's base address as an arguement
//

inline void call_back(char *str, int (*ptr)(const char*,...)){

	ptr(str);
	return;
}
