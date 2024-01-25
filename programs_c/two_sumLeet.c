/* leet code question 
 * given an array of elements and a integer called target we need to find out which 
 * two elements add upto the target and return the indices of the two elements in an array
 *
 *
 * complete this in less than O(n2) */


#include<stdio.h>
#include<stdlib.h>
struct hashNode{
	int data;
	struct hashNode *link;
};


struct hashNode **create_hashTable(int);

void hash_init(struct hashNode **hashTab, int size)
{
	int i;
	for(i = 0; i <= size; i++)
	{
		hashTab[i] = NULL;
	}


}
struct hashNode ** create_hashTable(int size)
{

	struct hashNode **hashTable = malloc((size+1) * sizeof(struct hashNode *));
	if(hashTable == NULL)
	{
		printf("malloc falied\n");
		exit(1);

	}
	return hashTable;
}

void print_hash_tab(struct hashNode **hashTab, int size)
{
	int i;
	struct hashNode *temp;
	printf("key ---------------------value\n");
	for(i = 0; i <= size; i++)
	{
		if(hashTab[i] != NULL)
		{
			
			printf("%d-----------------\t",i);
			temp = hashTab[i];
			while(temp != NULL)
			{
		       		printf("%d ",temp->data);
				printf("-->");
				temp = temp->link;
			}
			printf("\n");

		}

	}
}
void hash_entry(int value, int key, struct hashNode **hashTab)
{
	// add into hash table
	if(hashTab == NULL)
	{
		return;

	}

	if(key < 0) //checking if key is -ve or not 
		key = -(key);

	if(hashTab[key] == NULL){
		hashTab[key]  = malloc(1 *sizeof(struct hashNode));
		
		(hashTab[key])->data = value;
		(hashTab[key])->link = NULL;
	}
	else
	{
		//collision occured resolve collision
		//already a node exists perform seperate chaining
		struct hashNode *temp = malloc(1 * sizeof(struct hashNode));
		if(temp == NULL)
		{
			printf("failed to allocate memory in heap\n");
			exit(1);
		}

		temp->data = value;
		temp->link = NULL;

		//traverse all the list
		struct hashNode *trav = hashTab[key];
		while(trav->link != NULL)
			trav = trav->link;

		trav->link = temp;
	}
	
	


}
// finds biggest element in the array
int biggestEle(int *arr, int size)
{
	int max = 0;
	int i;
	for(i = 0; i < size; i++)
	{

		if(arr[i] > max)
		{
			max = arr[i];
		}


	}
	//if(max < 0)
		return 10000;
	//return max;
}

int * two_sum(int *nums, int numSize, int target, int *returnSize)
{
	int *arr = malloc(2 * sizeof(int));
	*returnSize = 2;
	int hashSize = biggestEle(nums, numSize);
 	struct hashNode** hashTab = create_hashTable(hashSize);
	hash_init(hashTab, hashSize);
	int i, diff;
	//creating hash table
	for(i = 0; i < numSize; i++)
	{
		hash_entry(i, nums[i], hashTab);
	}
	print_hash_tab(hashTab,hashSize );

	for(i = 0; i < numSize; i++)
	{
		diff = target - nums[i];
			if(diff < 0)
				diff = (-1) * (diff);
		if(hashTab[diff] != NULL)
		{
			arr[0] = i;
			arr[1] = hashTab[diff]->data;
			if(hashTab[diff]->link != NULL)
				arr[1] = hashTab[diff]->link->data;
				
			if(arr[0] != arr[1])
				return arr;
		}
	}




	
	return arr;
}
int main()
{
	int arr[] = {-1,-2,-3,-4,-5};
	int i;
	int returnSize;
	int *res = two_sum(arr, 5, -8,&returnSize );

	for(i = 0; i < 2; i++)
		printf("%d \t",res[i]);

}
