/* construct a single linked list based on the given input from user as a string
 * each and every character is a node in string */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	char data;
	struct node *link;
}NodeList;

bool isCircular = false;

NodeList *NodeHead = NULL;  //global head pointer for node list


void create_list(char *str)
{
	NodeList *temp, *prev =  NULL;

	int i;
	for(i = 0; str[i] != '\0'; i++)
	{

		if(str[i] == ' ')
			continue;
		temp = (NodeList *)malloc(1 * sizeof(NodeList));
		if(temp == NULL)
		{
			printf("failed to allocate memory in heap\n");
			exit(1);
		}
		temp->link = NULL;
		temp->data = str[i];

		if(NodeHead == NULL)
		{
			NodeHead = temp;
			
		}
		if(prev != NULL)
			prev->link = temp;

		prev = temp;



	}
	return;
}

void display_nodes()
{
	if(isCircular == true)
	{
		printf("Circular Linked List use other display option\n");
		return;
	}
	if(NodeHead == NULL)
	{
		printf("no nodes in list\n");
		return;

	}
	NodeList *temp = NodeHead;
	while(temp !=  NULL)
	{
		printf("%c\t",temp->data);
		temp = temp->link;
	}
	printf("\n");

	return;
}	

void display_circular()
{
	if(isCircular == false)
		return;
	
	if(NodeHead == NULL)
	{
		printf("no nodes in list\n");
		return;
	}


	NodeList *temp = NodeHead;

	do{
		printf("%c\t",temp->data);
		temp = temp->link;


	}while(temp != NodeHead);
	printf("\n");

	return;
}

void convert_circular()
{
	if(NodeHead == NULL)
	{
		printf("Head is pointing to null\n");
		return;
	}

	//traverse till end node
	NodeList *temp = NodeHead;
	while(temp->link != NULL)
		temp = temp->link;
	temp->link = NodeHead;
	
	isCircular = true;	

}

void push_to_queue(char *str)
{
	NodeList *temp = malloc(1 * sizeof(NodeList));
	if(NodeHead == NULL)
	{
		printf("node head is pointing null create a list first\n");
		return;
	}
	NodeList *head = NULL, *prev = NULL;
	
	int i;
	for(i = 0; str[i] != '\0'; i++)
	{

		if(str[i] == ' ')
			continue;
		temp = (NodeList *)malloc(1 * sizeof(NodeList));
		if(temp == NULL)
		{
			printf("failed to allocate memory in heap\n");
			exit(1);
		}
		temp->link = NULL;
		temp->data = str[i];

		if(head == NULL)
		{
			head = temp;

		}
		if(prev != NULL)
			prev->link = temp;

		prev = temp;



	}
	NodeList *trav = NodeHead;
	do{
		trav = trav->link;
	}while(trav->link != NodeHead);
	trav->link = head;
	temp->link =  NodeHead;	
	NodeHead = head;

		
}
int main()
{
	char name[100];
	char sname[100];
	char opt;
	while(1)
	{
		printf("----\t----\n");
		printf("a.create a single L.List\nb.display list\nc.Convert to Circular\nd.Display Circular\n");
		printf("e.Append to circular\n");
		printf("Select an option: ");
		scanf("%c",&opt);
		switch(opt)
		{
			case 'a':

				printf("Enter the name: ");
				scanf("%s",name);
				printf("creating a single linked list\n");
				create_list(name); //creates single linked list
				printf("\n");
				break;
			case 'b':
				printf("displaying nodes in list\n");
				display_nodes();
				printf("\n");
				break;
			case 'c':
				//convert to circular
				convert_circular();
				printf("converted to circular\n");

				break;
			case 'd':
				printf("Displaying Nodes inside Circular L.List\n");
				display_circular();
				break;
			case 'e':
				printf("Enter the name: ");
				scanf("%s",name);
				printf("appeding to existing linked lists\n");
				push_to_queue(name); //creates single linked list
				printf("\n");
				break;

		}
	}
	return 0;
}
