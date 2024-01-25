/* program to find out longest palindromic substring from a given string */
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool is_palindrome(char *str);
char buf[100];
char *longest_palindromic(char *str);
int main()
{
	char str[100];
	printf("Enter the string:");
	scanf("%[^\n]",str);
	printf("Entered string: %s\n",str);


//	printf("is palindrome: %d\n",is_palindrome(str));

	printf("longest palindromic substring: %s\n", longest_palindromic(str));
	return 0;
}

bool is_palindrome(char *str)
{
	int i, j;
	int len = strlen(str);
	//printf("len : %d\n",len);

	for(i = 0, j = len-1; i < j; i++, j--) 
	{
		if(str[i] != str[j])
			return false;

	}
	


	return true;
}

char *longest_palindromic(char *str)
{
	int i, j;
	char maxBuf[100];
	int size, maxsize = 0;
	for(i = 0;  str[i] != '\0'; i++)	
	{
		for(j = i+1; str[j] != '\0'; j++)
		{
			strncpy(buf, &str[i], j-i+1);
			buf[j-i+1] = '\0'; 


			if(is_palindrome(buf))
			{
				//if it is a palindrome sub string
				printf("substring: %s\n",buf);
				size = strlen(buf);
				if(size > maxsize)
				{
					maxsize = size;
					strcpy(maxBuf, buf);

				}
			}

		}
	}
	strcpy(buf, maxBuf);
	return buf;

}
