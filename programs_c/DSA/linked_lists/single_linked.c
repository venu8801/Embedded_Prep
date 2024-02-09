/* singly linked list and some operations on linked list */
#include<stdio_ext.h>
#include<stdlib.h>
#include "Node.h"
Node *head = NULL; // struct node *

void addBefore(int data);
void DisplayNodes()
{
	if(head == NULL)
	{
		printf("head is empty\n");
		return;

	}
	Node *temp = head;

	while(temp != NULL)
	{
		printf("%d   ", temp->data);
		temp = temp->link;

	}
	return;


}

/* delete duplicate nodes */
void deleteDuplicates(){
	if(head == NULL)
		return;
	struct node *p = head, *q , *prev = p, *temp;
	while(p != NULL){
		q = p->link;
		prev = p;
		while(q != NULL){
			
			if(p->data == q->data){ //delete q
				prev->link = q->link;
				temp = q;
				q = q->link;
				free(temp);
				

			}
			else{
				prev = q;
				q = q->link;
			}

		}

		p = p->link;
	}

	return;
}



/* finding middle node(s) in a single pass */
void find_middle(){
	if(head == NULL){
		printf("Head is NULL list is empty\n");
		return;
	}
	struct node *fast = head, *slow = head, *prev = NULL;
	while( (fast != NULL) && (fast->link != NULL) ){
		prev = slow;
		slow = slow->link;//jump one node
		fast = fast->link->link; //jump two nodes
	}
	if(fast == NULL) //even num of nodes
	{
		printf("Middle nodes data is :%d and %d\n",prev->data,slow->data);
		return;
	}
	printf("Middle node data : %d\n",slow->data);
	return;
}

void addAfter(int data)
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
	temp = head;
	while(temp->link != NULL)
		temp = temp->link;
	Node *ptr;
	if( !( ptr = (Node *)malloc(1 * sizeof(Node *)) ) )
	{
		//if it becomes null	
		printf("malloc failed\n");
		exit(-1);

	}
	ptr->data = data;
	ptr->link = NULL;
	temp->link = ptr;
	return;



}

void create_list(int *arr, int size)
{
	int i;
	Node *ptr, *prev = NULL, *start = NULL;
	for(i = 0; i < size; i++)
	{
		if( !(ptr = (Node *)malloc(1 * sizeof(Node))) )
		{
			printf("malloc failed\n");
			exit(-1);
		}
		ptr->data = arr[i];
		ptr->link = NULL;
		if(prev != NULL)
			prev->link = ptr;
		if(start == NULL)
			start = ptr;  //first node in list of nodes
		prev = ptr;
				

	}
	if(head == NULL)
		head = start;
	else
	{
		prev = head;
		while(prev->link != NULL) //re-using prev pointer for traversal
			prev = prev->link;
		prev->link = start;

	}
	
}


void deleteAfter(int data)
{
	if(head ==  NULL)
	{
		printf("nothing to delete\n");
		return;

	}
	if(head->link == NULL)
	{

		printf("only one node in list\n");
		return;
	}
	Node *temp = head, *ptr;
	while(temp->link != NULL)
	{
		
		if(temp->data == data)
		{
			printf("--node found\n");
			//node found
			ptr = temp->link;
			temp->link = ptr->link;
			free(ptr);
			return;
		}

		
		temp = temp->link;
	}


}


void deleteParticular(int data)
{
	if(head == NULL)
	{
		printf("linked list is empty\n");
		return;

	}
	if(head->link == NULL)
	{
		if(head->data == data)
		{
			free(head);
			head = NULL;
			return;

		}

	}




	Node *temp, *prev;
	temp = head;
	while(temp->link != NULL)
	{
		if(temp->data == data)
			
			//delete that node
			if(temp != head)
			{
				prev->link = temp->link;
				free(temp);
				return;
			}
			//if it is head
			prev = head;
			head = head->link;
			free(prev);
			return;
			
		}
		prev = temp;
		temp = temp->link;
	

	printf(" -------------node not found-------------------\n");
	return;
}

int swap_by_link(struct node *head_node, int n1, int n2)
{
	if(head_node == NULL)
	{
		printf("Head node is empty\n");
		return -1;	
	}
	struct node *p, *q, *r, *s;
	p = head_node;
	q = head_node;
	int pos1 = 0, pos2 = 0;
	while(p != NULL)
	{
		if(p->data == n1)
			break;
		pos1++;
		r = p;  // r is prev pointer to p
		p = p->link;
	}

	while(q != NULL)
	{
		if(q->data == n2)
			break;
		pos2++;
		s = q;
		q = q->link;

	}


	if(p == NULL || q == NULL)
	{
		printf("node(s) not found\n");
		return -1;
	}
	
	struct node *temp;
	
	temp = q->link;
	q->link = p->link;
	p->link = temp;

	if(p == head)
	{
		head = q;
		s->link = p;
	}
	else if(q == head)
	{
		head = p;
		r->link = q;

	}
	else
	{
		s->link = p;
		r->link = q;

	}

	return 0;



}
void reverse_nodes()
{
	if(head == NULL)
		return;
	if(head->link == NULL)
		return;

	Node *prev = NULL, *curr = head, *nxt;

	while(curr != NULL)
	{
		nxt = curr->link;
		curr->link = prev;
		prev = curr;
		curr = nxt;


	}

	head = prev;



}

void reverse_node_from_pos(int pos)
{
	if(pos < 0)
	{
		printf("-ve pos\n");
		return;
	}


	if(head == NULL)
	{
		printf("list is empty\n");
		return;

	}

	int cpos = 0;
	struct node *thead = head, *tprev;
	while(thead != NULL )
	{
		cpos++;
		if(cpos == pos )
			break;
		tprev = thead;
		thead = thead->link;
	}

	struct node *prev = NULL, *curr = thead, *next;
	while(curr != NULL)
	{
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	
	thead = prev;
	tprev->link = thead;


}

int main()
{
	while(1)
	{

		char opt;
		int data;
		printf("-----------------------------Singly Linked List---------------------------------\n");
		printf("a.Add a node before\nb.Display All nodes\nc.Add after a node\nd.Create List\ne.Delete after node\n");
		printf("f.Delete particular node\ng.Swap two nodes (links)\nh.reverse nodes\ni.reverse from pos\nj.find middle node\n");
		printf("k.delete duplicates\n------z.exit-------\n");
		printf("Select an option: ");
		__fpurge(stdin);
		scanf("%c",&opt);
		switch(opt)
		{
			case 'a':
				printf("Selected Add a node before\n");
				printf("Enter data inside node: ");
				scanf("%d",&data);
				addBefore(data);
				break;
			case 'b':
				printf(" \"Selected Display all nodes\" \n");
				DisplayNodes();
				break;
			case 'c':
				printf(" \"Selected Add after a Node\" \n");
				printf("Enter data inside node: ");
				scanf("%d",&data);
				addAfter(data);
				break;
			case 'd':
				printf(" \"Selected Create a list\" \n");
				printf("Enter size of arr: ");
				scanf("%d",&data); //re-using data var as size of arr
				int *arr;
				if( !(arr = (int *)malloc(data * sizeof(int) )) )
				{
					printf("malloc failed\n");
					exit(-1);
				}
				int i;
				for(i = 0; i < data; i++)
				{
					scanf("%d",(arr + i));

				}
				__fpurge(stdin);
				create_list(arr, data);
				break;
			case 'e':
				printf(" \"Selected Delete Node After\" ");
				printf("Enter node to delete: ");
				scanf("%d",&data);
				deleteAfter(data);
				break;
			case 'f':
				printf(" \"Selected Delete particular node\" ")	;
				printf("Enter node to delete: ");
				scanf("%d",&data);
				deleteParticular(data);
				break;
			case 'g':
				printf("\"Selected option: Swap two nodes\" ");
				printf("Enter n1: ");
				scanf("%d",&data);
				int n2;
				printf("Enter n2: ");
				scanf("%d",&n2);

				int ret = swap_by_link(head, data, n2);
				if(ret)
					printf("failed to swap\n");
				else
					printf("nodes swapped\n");
				break;
			case 'h':
				printf("reverse nodes\n");
				reverse_nodes();
				break;

			case 'i':
				printf("reverse nodes\n");
				printf("enter pos: ");
				scanf("%d",&data);
				reverse_node_from_pos(data);
				break;
	
			case 'j':
				printf("----Finding Middle nodes----\n");
				find_middle();
				break;
			case 'k':
				printf("------------Delete Duplicates----------\n");
				deleteDuplicates();
				break;
			case 'z':
				printf("----------Exit---------------\n");
				exit(0);


		}

	}

















}
