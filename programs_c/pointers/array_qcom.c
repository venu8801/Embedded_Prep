/*     5. Find first and last positions of a most repeated element in a sorted array
                      example:  array[] = {1 3 8 8 8 8 8 8 9 9 9 9 10 10}
Output: 8 is most repeated first position is 2ed and last position is 7th  */


#include <stdio.h>
#include <stdlib.h>

void arr_most(int *arr, int numSize)
{
	if(arr == NULL)
		return;
	int i, j, count, maxCount = 0, first_pos = 0, last_pos = 0, repeated = 0;

	for(i = 0; i < numSize; i++){
		count  = 1; //reset count  
		for(j = i+1; j < numSize; j++){
			if(arr[i] == arr[j])
				count++;
			if(count > maxCount)
			{	
				repeated = arr[i];
				first_pos = i;
				last_pos = j;
				maxCount = count;
				
			}
		}
	}

	printf("Most repeated element: %d  F-pos:%d  L-pos:%d\n",repeated, first_pos, last_pos);


}


int main()
{
	int arr[] = {1, 3, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 10, 9};
	
	arr_most(arr, 14);

	return 0;
}
