#include<stdio.h>
int main()
{
	
	int arr[] = {0,0,0,0,2,3,0,4};

	int i, j, end_index = 0, k;
	for(i = 0; i < 8; i++)
	{
			if(arr[i] == arr[i+1])
			{
				
				end_index++;



			}
			if(end_index != 0)
			{

				for(j = end_index, k = 0; j < 8; j++, k++)
				{
					arr[k] = arr[j];


				}
				end_index = 0;
			}

		

		




	}


	for(i = 0; i < 8; i++)
	{
		printf("%d  ",arr[i]);
	}





	return 0;
}
