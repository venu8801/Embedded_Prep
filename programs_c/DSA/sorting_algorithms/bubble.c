/* bubble sort on array */

#include<stdio.h>

int main()
{	

	int arr[5] = {5,4,3,1,2};

	int i, j , k;

	for(i = 0; i < sizeof(arr)/4 - 1; i++)
	{

		for(j = 0; j < (sizeof(arr)/4 - i) - 1; j++ )
		{

			if(arr[j] > arr[j+1])
			{
				//swap
				arr[i] = arr[i] ^ arr[j+1];
				arr[j+1] = arr[i] ^ arr[j+1];
				arr[i] = arr[i] ^ arr[j+1];


			}


		}
	}



	//printing
	for(i = 0; i < sizeof(arr)/4; i++)
	{

		printf(" %d  ", arr[i]);

	}


	


	return 0;
}
