/* string reverse function */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void string_reverse(char *str)
{
	int len = strlen(str);

	if(str == NULL)
	{
		printf("null in string\n");
		return;
	}
	int i, j;
	for(i = 0, j = len -1; i < j; i++, j--)
	{

		str[i] = str[i] ^ str[j];
		str[j] = str[i] ^ str[j];
		str[i] = str[i] ^ str[j];




	}
	

	return;

}

int main()
{

	char str[] = "VenuGopal";
	string_reverse(str);
	printf("out: %s\n",(str));
	return 0;
}
