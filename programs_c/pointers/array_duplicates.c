/* 7) Remove duplicates from an array without using any library.
WTD: Navigate through the array, identifying and removing any repetitive occurrences of
numbers, ensuring each number appears only once.
(e.g.: I/P: [1,1,2,2,3,4,4]; O/P: [1,2,3,4]) */

/* moving all duplicates to last */
#include <stdio.h>
int move_dups(int *arr, int numSize){
	if(arr == NULL)
		return -1;

	int i,j,k,l=numSize-1,f=0;
	for(i = 0; i < l; i++){
		for(j = i+1; j <=l; j++){
			if(arr[i] == arr[j]){
				//found duplicate
				printf("i:%d\n",arr[i]);
				for(k = j; k <numSize-1; k++){
					arr[k] = arr[k+1];
					f=1;
				}
				l--;//reducing search scope
				j--;  //checking blindspot
				arr[k] = arr[i];


			}

		}
	}
	return 0;

}



int main(){
	
	int arr[] = {1,1,1,1,3,4,1};
	move_dups(arr, 7);
	int i;
	for(i = 0; i < 7; i++){
		printf("%d ",arr[i]);
	}


	return 0;
}
