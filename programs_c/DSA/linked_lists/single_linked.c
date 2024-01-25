/* single linked list create a node and add in the middle of the node */
#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *link;
	char data; 
};



struct node *head = NULL;


void create_node_after(char data)
{
	struct node *temp;

	temp = (struct node *)malloc(1 *sizeof(struct node));
	if(temp == NULL)
	{

		printf("failed to allocate memory\n");
		exit(1);
	}
	temp->data = data;
	temp->link = NULL;

	if(head == NULL)
	{
		head = temp;
		return;
	}
	struct node *traverse = head;
	while(traverse->link != NULL)
		traverse = traverse->link;
	traverse->link = temp;
	return;

}


void display()
{
	if(head == NULL)
	{		
		printf("Empty list nothing to display\n");
		return;
	}
	struct node *temp = head;
	while(temp != NULL)
	{	
		printf("data: %c\t",temp->data);

		temp = temp->link;
	}
	
	printf("\n");
}

void insert_middle(char data)
{
	if(head == NULL && head->link == NULL) // if only one node exists
	{
		create_node_after(char data);
		return;
	}
	
	
	struct node *fast, *slow, *slow_next;
	*fast = head->link, *slow = head;
	
	while(fast != NULL && fast->link != NULL)
	{
		
		

		slow = slow->link;
		slow_next = slow->link;
		fast = fast->link->link;
	}
	slow->link = malloc(1 * sizeof(struct node));
	slow->link->link = slow_next;
	


}


int main()
{

	return 0;
}
