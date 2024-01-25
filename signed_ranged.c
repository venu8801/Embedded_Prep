#include<stdio.h>
int main()
{
	unsigned char x = 500;
	printf("%c  %d\n",x,x);
	int i;
	for(i = 7; i >=0; i--)
	{
		if(x & (0x1 << i) )
			printf("1");
		else
			printf("0");

	}
}
