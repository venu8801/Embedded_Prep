/* DQ or Double Ended Queue */

#include <stdio.h>

#define SIZE 7

int f_ind = -1, r_ind = -1;

void add_front_end(int data)
{
	if(f_ind == -1)
		f_ind++;
	else if( (f_ind == 0 && r_ind = SIZE -1) || (f_ind = r_ind + 1))
	{
		//queue is full
		printf("queue is full\n");
		return;
	}
	else if(f_ind )


}
