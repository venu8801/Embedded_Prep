#include<stdio.h>
int main()
{
	char *p = "Akhil";
	printf("addR: %p\n",p);

	p = (char *)"Ayyagaru";
	printf("addA: %p\n",p);
	
	
	printf("%s\n",p);

	return 0;
}
