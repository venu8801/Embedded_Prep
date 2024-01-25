/* implementing stack DS */

/* array implementation */

#define ARR_SIZE 5
int ind = -1;
int arr[ARR_SIZE]; // limited array


/* push operation */
int push(int data)
{

	ind++;
	if(ind >= ARR_SIZE - 1)
	{
		printf("Stack is full\n");
		return -1;
	}
	arr[ind] = data;
	return 0;
}


/* pop operation  LIFO*/
int pop(void)
{
	if(ind < 0)	
	{
		printf("stack is empty cannot pop\n");
		return -1;
	}
	ind--;

}

/* show the elements in stack */
void display()
{
	if(ind == -1)
	{
		printf("nothing to display\n");
		return;
	}
	int i;
	for(i = 0; i < ARR_SIZE; i++)
	{
		printf(" %d ", arr[i]);


	}

}



