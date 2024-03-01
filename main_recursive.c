/* recursive print 1 to 10 */

#include <stdio.h>
int print_num()
{
	static int num = 0;
	 
	if(num > 10)
		return 1;
	num++;
	printf("%d\n",num);
	print_num();
	return 0;

}

int main()
{
	print_num();

	return 0;
}
