#include <stdio.h>
#include <stdint.h>
int main()
{
	int16_t val = 0x1234;
	int16_t *ptr = &val;
	printf("0x%x\t",*((char *)ptr));
	printf("%p\n",ptr);
	printf("%d - %p\n",*((char *)ptr), ptr);
	(*ptr)++;
	printf("%d - %p\n",*((char *)ptr), ptr);
	return 0;

}
