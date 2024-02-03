/* reverse a string using recursion */
#include <stdio.h>
#include <string.h>

void string_reverse(char *str, int s, int e)
{

	if(str == NULL)
		return;

	if(s >= e)
		return;
	//swap
	str[s] = str[s] ^ str[e];
	str[e] = str[s] ^ str[e];
	str[s] = str[s] ^ str[e];
/*
	char temp = str[s];
	str[s] = str[e];
	str[e] = temp;*/
	string_reverse(str,++s, --e);
	

	return;
}	

void dummy(int s, int e)
{
	printf("s:%d\t e:%d\n",s,e);
	return;
}

int main()
{
	char str[] = "ilaBgnarjahBiaJ";
	int e = strlen(str) - 1;
	
	int a = 0, b = 3;
//	dummy(++a,--b);	
	printf("length: %d\n",e);
	string_reverse(str, 0, e);

	printf("---> %s\n",str);

	return 0;


}
