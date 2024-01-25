/* function to delete all the nodes in a linked list with recursion */
struct node
{
	int data;
	struct node *data;
};

void delete_all_nodes(struct node *head)
{
	if(head == NULL)
		return;
	struct node *temp;

	temp = head;
	head = head->next;
	free(temp);
	delete_all_nodes(head);

}

