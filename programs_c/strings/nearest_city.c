/* array of pointers containing cities 
 *{hyd,goa,delhi,hyd,ahmd,mum} 
 * input: hyd, goa	hyd
 *
 */


#include <stdio.h>
#include <string.h>
#include <limits.h>

int nearest_ofAll(char **cities, const int size, char *ip1, char *ip2){

	int i, k, res;
	short int ip1_ind = -1, ip2_ind[100] = {0};
		for(i = 0, k = 0; i < size; i++){

			if(strcmp(ip1, cities[i]) == 0)
			{
				//found goa
				ip1_ind = i;

			}
			if(strcmp(ip2, cities[i]) == 0) 
			{
				//found ip2
				ip2_ind[k++] = i;
			}


		}

		if(k == 1)
			return ip2_ind[k];
		else if(k == 0 || ip1_ind == -1)
			return -1;
		else
		{	
			//printf("ip1[i] : %d ",ip1_ind);
			int min = INT_MAX, min_ind = 0;
			//multiple indexes
			for(i = 0; i < k; i++)
			{
				//printf("ip2[i]: %d\n",ip2_ind[i]);
				res = ip1_ind - ip2_ind[i];
				if(res < 0)
					res = -(res);
				if(res < min)
				{
					min = res;
					//printf("min: %d\n",min);
					min_ind = ip2_ind[i];
				}
			}
			
			return min_ind;
		}
		return -1;

}


int main()
{
	char *cities[] = {"hyd","goa","delhi","hyd","blr","hyd","ahmd","mum","hyd"};
	int i;
	for(i = 0; i < 9; i++)
		printf("%s\t",cities[i]);
	printf("\n");
	char c1[10] = "blr";
	char c2[10] = "hyd";
	int res = nearest_ofAll(cities, 9, c1, c2);
	printf("nearest %s of %s is %d\n",c1,c2,res);

	return 0;
}
