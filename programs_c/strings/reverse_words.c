#include<stdio.h>
int main()
{
	char str[100];
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	

	printf("Str: %s\n",str);
	int i,j, k;
	int st=0, end = 0;
	for(i = 0; str[i] != 0; i++)
	{

		
		if(str[i] == ' ' || str[i+1] == 0)
		{
			if(str[i+1] == 0)
				end = i;
			else
				end = i-1;
			for(j = st, k = end; j < k; j++, k--)
			{
				str[j] = str[j] ^ str[k];
				str[k] = str[j] ^ str[k];
				str[j] = str[j] ^ str[k];
			}
			st = end + 2;
		}

	}


	printf("Str: %s\n",str);
	return 0;
}
