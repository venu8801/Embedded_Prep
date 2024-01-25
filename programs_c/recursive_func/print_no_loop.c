/* print a given string 'n' no. of times without using loop */
/* using recursion */
#include<stdio.h>

void print_str(char *str, int cnt)
{
	if(cnt == 0)
		return;
	printf("%s\n",str);
	cnt--;
	print_str(str, cnt);



}


int main()
{
	print_str("hello", 5);  

	return 0;
}
