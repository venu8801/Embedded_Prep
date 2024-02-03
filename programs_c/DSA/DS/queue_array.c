/* circular queue implementation using a fixed array */

#include <stdio.h>

#define SIZE 5

int f_ind = -1, r_ind = -1;
//f_ind for deleting and r_ind for adding 
void add(int data)
{
	if(f_ind == -1)
		f_ind++;
	
	else if( ( (r_ind == SIZE-1)  && f_ind == 0) || (r_ind == f_ind - 1) )  //queue full
	{
		printf("queue is full\n");
		return;
	}
	else if(r_ind == SIZE-1) //space at front available
		r_ind = 0;
	else
		r_ind += 1;

	arr[r_ind] = data;
	return



}

void delete(int data)
{
	if(f_ind == -1) //queue empty
	{
		printf("No elements in queue\n");
		return;
	}
	else if(f_ind == r_ind) // only one ele present
	{
		f_ind = -1, r_ind = -1;
		return;
	}
	else if(f_ind == SIZE - 1) //resetting to zero
	{
		f_ind = 0;
	}
	else
		f_ind -= 1;
	return;


}

void display()
{
	if(_ind == -1)
	{	
		printf("queue is empty\n");
		return;
	}
	int i;
	if(r_ind < f_ind)
	{
		for(i = f_ind; i < SIZE-1; i++ )
			printf("%d\t",arr[i]);
		for(i = 0; i <= r_ind; i++)
			printf("%d\t",arr[i]);


	}
	else{
		for(i = f_ind; i <= r_ind; i++)
		{
			printf("%d\t",arr[i]);

		}
	}






}





