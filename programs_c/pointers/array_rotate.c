/* 9) Rotate an array to the right by k steps.
WTD: Modify the array by moving its elements to the right, wrapping them around when
they reach the end, for a specified number of steps.
(e.g.: I/P: [1,2,3,4,5], k=2; O/P: [4,5,1,2,3] ) */

/* rotate an array to left by k times */
#include <stdio.h>
int rotate_arrayLeft(int *arr, int numSize, int k){
	if(arr == NULL)
		return -1;
	int i,temp,j;
	for(i = 0; i < k; i++){
		temp = arr[0];
		for(j = 0; j < numSize - 1; j++){
			arr[j] = arr[j+1];
		}
		arr[j] = temp;
	}
	return 0;
}


int main()
{
	int arr[] = {1,2,3,4,5};
	rotate_arrayLeft(arr, 5, 1);
	int i;
	for(i = 0; i < 5; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
