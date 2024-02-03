/* tree data structure */
#include <stdio.h>
#include <stdlib.h>

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


void pre_order(struct node *root)
{
	struct node *ptr = root;
	if(ptr == NULL)
		return;

	//  N-L-R
	printf("%c\t",ptr->data);

	//traverse left
	pre_order(ptr->lchild);

	//traverse right
	pre_order(ptr->rchild);
	
	return;
}


void post_order(struct node *root)
{
	struct node *ptr = root;
	if(ptr == NULL)
		return;

	// L-R-N
	//traverse left
	post_order(ptr->lchild);

	//traverse right
	post_order(ptr->rchild);

	//view node
	printf("%c\t",ptr->data);

	return;


}


void in_order(struct node *root)
{
	struct node *ptr = root;
	if(ptr == NULL)
		return;

	//L-N-R
	in_order(ptr->lchild);

	printf("%c\t",ptr->data);

	in_order(ptr->rchild);

	return;
}

int l_tree = 0, r_tree = 0;

/*void height_treedd(struct node *root)
{
	struct node *ptr = root;

	if(ptr == NULL)
		return;

	height_tree(ptr->lchild); //recursively traversing left tree
	l_tree++;

	height_tree(ptr->rchild);
	r_tree++;
	
	return;
}
*/


void l_tree_height(struct node *root)
{

	struct node *ptr = root;

	if(ptr == NULL)
		return;
	
	l_tree++;
	l_tree_height(ptr->lchild);

	return;


}

void r_tree_height(struct node *root)
{

	struct node *ptr = root;

	if(ptr == NULL)
		return;
	
	r_tree++;
	r_tree_height(ptr->rchild);

	return;


}
int main()
{
	//constructing a tree
	struct node *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10;
	
	//root node 
	n1 = createNode('A');
	/*---------A--------
	-------/---\-------
	------/-----\-------
	-----B------C-------
	----/-\----/-\-------
	---D---E--F----G
	--/-\---\-----/-----------
	-----H---I--J----------*/

	
	n2  = createNode('B');
	n1->lchild = n2;

	n3 = createNode('C');
	n1->rchild = n3;
	n4 = createNode('D');
	n5 = createNode('E');
	n6 = createNode('F');
	n7 = createNode('G');
	n8 = createNode('H');
	n9 = createNode('I');
	n10 = createNode('J');
	
	n2->lchild = n4;
	//n4 leaf node
	n4->lchild = NULL;
	n4->rchild = NULL;

	n2->rchild = n5;
	n5->lchild = n8;
	n5->rchild = n9;
	//n8 and n9 leafnodes
	n8->lchild = NULL;
	n8->rchild = NULL;
	n9->lchild = NULL;
	n9->rchild = NULL;

	n3->lchild = n6;
	n3->rchild = n7;
	//n6 leaf node
	n6->lchild = NULL;
	n6->rchild = NULL;

	n7->lchild = n10;
	n7->rchild = NULL;
	
	printf("\n---pre order-----\n");
	pre_order(n1);

	printf("\n-----post order--------\n");
	post_order(n1);

	printf("\n----in order -------\n");
	in_order(n1);

	r_tree_height(n1);
	l_tree_height(n1);

	printf("l_sub : %d\t r_sub :%d\n",l_tree,r_tree);

	if(r_tree > l_tree)
	{
		printf("height: %d\n",r_tree + 1);
	}

	else
	{
		printf("height: %d\n",l_tree + 1);
	}
		
	
	return 0;
}
		
