#include<stdio.h>
#define RTKBT_INFO(str, args...) printf(str"\n", args)
int main()
{
	RTKBT_INFO("hello  %d and %d",2357,2359);
}
