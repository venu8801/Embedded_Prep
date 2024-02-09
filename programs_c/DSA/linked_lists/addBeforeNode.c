#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
extern Node *head;
void addBefore(int data)
{
	Node *temp;
	if(head == NULL)
	{
		temp = (Node *)malloc(1 * sizeof(Node));
		if(temp == NULL)
		{
			printf("malloc failed\n");
			exit(-1);
		}
		temp->data = data;
		temp->link = NULL;
		head = temp;
		return;
		
	}
	
	temp = (Node *)malloc(1 * sizeof(Node ));
	if(temp == NULL)
	{
		printf("malloc failed\n");
		exit(-1);

	}
	temp->data = data;
	temp->link = head;
	head = temp;
	return;
}

