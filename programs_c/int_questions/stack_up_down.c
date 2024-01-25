/* WAP to find out whether stack grows upwards or downwards */
#include<stdio.h>
void func(int *main_local)
{
	int func_local;

	if(main_local < (&func_local) )
		printf("stack grows upwards\n");
	else
		printf("stack grows down wards\n");


}
int main()
{

	int main_local;

	func(&main_local);

}
