#include <stdio.h>
void str_modify(char str[])
{
	str[0] = 'a';
	return;
}
int main()
{
	unsigned int val = 0xfffffff8;

	int i;
	for(i = 31; i >= 0; i--)
	{
		if(val & ((0x1) << i))
			printf("1");
		else
			printf("0");


	}
//	str_modify("hello");
	return 0;
}
