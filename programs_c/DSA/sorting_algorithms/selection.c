/* selection sorting */
#include<stdio.h>
int main()
{
	int arr[5] = {5,4,3,2,1};

	printf("sizeof arr: %d\n",sizeof(arr));
	int i, j, k;

	//printing array
	for(i = 0; i < sizeof(arr)/4; i++)
	{

		printf("%d  ",arr[i]);

	}

	for(i = 0; i < sizeof(arr)/4 - 1; i++)
	{
		for(j = i+1; j < sizeof(arr)/4; j++)
		{
			if(arr[i] > arr[j])
			{
				/*swap*/
				arr[i] = arr[i] ^ arr[j];
				arr[j] = arr[i] ^ arr[j];
				arr[i] = arr[i] ^ arr[j];

			}
			printf("\n");
			for(k = 0; k < sizeof(arr)/4; k++)
			{

				printf("%d  ",arr[k]);
			}

		}

		printf("\n-\n");
	}



	printf("--------------------\n");
	//printing array
	for(i = 0; i < sizeof(arr)/4; i++)
	{

		printf("%d  ",arr[i]);

	}

	return 0;

}
