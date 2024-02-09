/* find the largest and smallest number in an array */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int arr_max(int *arr, int numSize, int *maxEle, int *minEle){
	if(arr == NULL)
		return -1;
	
	*maxEle = INT_MIN;
	*minEle = INT_MAX;

	int i;
	for(i = 0; i < numSize; i++){
		if(arr[i] > *maxEle){
			*maxEle = arr[i];
		}
		if(arr[i] < *minEle){
			*minEle = arr[i];

		}

	}
	return 0;

}


int main()
{
	int arr[] = {1,25,2,5,15,20,-5,-1,0,900};
	int maxEle, minEle;
	arr_max(arr, 10, &maxEle, &minEle);
	printf("max:%d\tmin:%d\n",maxEle,minEle);
	return 0;
}
