/* 7) WAP to return 0-3 bits of the integer
     Ex: int 0x12345678; */


#include<stdio.h>

int ret_bits(unsigned int num)
{
	return (num  & (0xF << 0) );
}

int main()
{

	unsigned int x = 0x12345678;
	printf("0 to 3 bits in hex: 0x%x\n",ret_bits(x));
	return 0;
}
