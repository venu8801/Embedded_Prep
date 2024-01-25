/* program to eliminate consecutive zeroes from an array */
#include<stdio.h>
int main()	
{




	int arr[ ] = { 0, 0, 1, 0, 1, 1, 1, 3, 3, 0, 0, 0}, i;
	int n=sizeof(arr)/ sizeof(arr[0]);


	int prev;
//	printf("enter elements: ");
/*	for(i = 0; i < n; i++)
	{
	//	scanf("%d",&arr[i]);
	
	}
	printf("------------\n");*/


	int j,k,flag = 0;
	int streak_break = 0;
	for(i = 0; i < n;i++ )
	{
//		printf("------------i = %d\n",i);
		
			if(arr[i] == arr[i+1]|| (arr[i]==prev &&  streak_break != 1))
			{
				prev=arr[i];
			//	printf("true\n");
				for(k = i; k < n; k++)
				{
			//	printf("true1\n");
					arr[k] = arr[k+1];
				}
				n--;
				flag = 1;
				streak_break = 0;
				
			}
			else
				streak_break = 1;
			if(flag == 1)
			{
			//	printf("true2\n");
				i--;
				flag = 0;
				
			}
			



	}
	//print array
	for(i = 0; i < n; i++)
	{
		printf("%d  ",arr[i]);
	}
}
