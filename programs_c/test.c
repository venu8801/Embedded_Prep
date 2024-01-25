#include<stdio.h>
struct hello
{

	int data;
	char bdinfo;

};
int main()
{
	struct hello *h, eg = {24, 'm'};
	h = &eg;
	printf("%d", &h->data );

	return 0;
}
