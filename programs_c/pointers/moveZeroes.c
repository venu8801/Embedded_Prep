/* 12) Move all zeros to the left of an array while maintaining the order of other numbers.
WTD: Reorder the array by moving all zero values to the leftmost positions while ensuring
the relative order of the non-zero numbers remains unchanged.
(e.g.: I/P: [1,2,0,4,3,0,5,0]; O/P: [0,0,0,1,2,4,3,5] ) */


#include <stdio.h>
#include <stdlib.h>

int arr_moveZeroes(int *arr, int numSize){
	if(arr == NULL)
		return -1;


	int i,j,start = 0;
	for(i = 0; i < numSize; i++){
		if(arr[i] == 0){
			//moving
			for(j = i; j > start; j--){
				arr[j] = arr[j-1];
			}
			arr[start] = 0;
			start++;

		}

	}
	return 0;

}


int main(){
	
	int arr[] = {1,2,0,4,3,0,5,0};
	arr_moveZeroes(arr, 8);
	int i;
	for(i = 0; i < 8; i++){
		printf("%d ",arr[i]);
	}


	return 0;
}
