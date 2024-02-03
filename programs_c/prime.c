#include <stdio.h>
int main()
{
	int num;
	printf("enter num: ");
	scanf("%d",&num);
	
	int i = 2;
	int factors = 2;
	while(i !=  num)
	{
		if(num % i == 0)
			factors++;
		i++;


	}

	if(factors > 2)
		printf("Composite number\n");
	else
		printf("Prime number\n");




}


