/* find out max num of consecutive 1s in a binary array 
 * example:
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
*/

#include<stdio.h>
int main()
{
	int cnt = 1, maxCnt = 0;
	int arr[] = {1,1,0,1,1,1};

	int i;
	for(i = 0; i < 6; i++)
	{	
		if(arr[i] == arr[i+1]) //consecutive
		{
			cnt += 1;
			if(cnt > maxCnt)
			{
				//storing max count
				maxCnt = cnt;
			}

		}
		else 
			cnt = 1;

	}

	printf("max no. of consecutive 1s: %d\n",maxCnt);
	 return 0;
}
