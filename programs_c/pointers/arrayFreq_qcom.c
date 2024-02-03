/* Find most frequent element in an array and how many times it is repeated
                      example: array[]= {5 6 7 8 9 5 6 8 6 8 6 5 7 6 8 5 6 5}  */

#include <stdio.h>
#include <stdlib.h>

void freq_count(int *arr, int numSize){
	if(arr == NULL)
		return;
	int i, j, count, maxFreq, maxCount = 0;
	for(i = 0; i < numSize; i++){
		count = 1;
		for(j = i+1; j < numSize; j++){
			if(arr[i] == arr[j])
				count++;
			if(count > maxCount){
				maxFreq = arr[i];
				maxCount = count;
			}
		}
	}
	printf("Most Frequent Element: %d Max Freq: %d\n",maxFreq, maxCount);
	return;


}


int main()
{
	int arr[] = {5, 6, 7, 8, 9, 5, 6, 8, 6, 8, 6, 5, 7, 6, 8, 5, 6, 5} ;
	
	freq_count(arr, 18);

	return 0;
}
