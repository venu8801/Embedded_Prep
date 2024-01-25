/* tree data structure */
struct node
{
	struct node *lchild;
	char data;
	struct node *rchild;

};


struct node * createNode(char data)
{
	struct node *ret = (struct node *)malloc(1 * sizeof(struct node));
	if(ret == NULL)
	{
		printf("failed to allocate memory in heap\n");
		exit(1);
	}
	ret->data = data;
	ret->lchild = NULL; //left child node
	ret->rchild = NULL;// right child node 

	return ret;
}

int main()
{
	//constructing a tree
	struct node *n1, *n2, *n3, *n4, *n5, *n6, *n7;
	
	//root node 
	n1 = createNode('A');
/*
	---------A--------
	-------/---\-------
	------/-----\-------
	-----B------C-------
	----/-\----/-\-------
	---D---E--F----G
	--/-\-----/---/-\----------
	-----H----I--J---K--------

	*/
	n2  = createNode('B');
	n1->lchild = n2;

	n3 = createNode('D');
	n4 = createNode('E');
	n2->lchild = n3;
	n2->rchild = n4;


	
	
	return 0;
}
		
