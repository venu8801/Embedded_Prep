/* print elements in array without using loop */
#include<stdio.h>

void print_int_arr(int *arr, int n, int size)
{
	//n is iterator
	if(arr == NULL)	
	{
		printf("null inside pointer\n");
		return;
	}
	if(n == size)
		return;
	printf("%d ",arr[n]);
	n++;
	print_int_arr(arr, n, size);

}

int main()
{
	int arr[9] = {0,5,6,3,2,7,9,1,99};

	print_int_arr(NULL,0, 9);


	return 0;
}
