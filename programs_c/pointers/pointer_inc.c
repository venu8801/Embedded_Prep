/* incrementing a pointer */

#include <stdio.h>

int main()
{
	int val[] = {90, 12, 13};

	int *ptr = val;
	
	printf("%p\n",ptr);
	printf("val: %d\n",*ptr++); //oE L  <---- R so *(ptr++)  this expression is equvivalent to this.
				    //first ptr++ happens as ptr is postfix increment first ptr address gets substituted in the expression and then ptr gets incremented
				    //so this is similar to 
				    //	
				    //
				    //	*(ptr);
				    //	ptr = ptr + 1;
				    //
				    //
				    //later pointer value gets incremented to point next 4 bytes that is points 12
				    //
	printf("addr: %p\t data: %d\n",ptr,*ptr); //prints 2nd element address and data

	printf("addr:%p\t%d\n",ptr,*++ptr); // first increment operations happens later dereferencing happens
					    //
					    //
					    // this is similar to *(++ptr) 
					    //	prefix increment so pointer address increments and later pointer gets dereferenced
					    //
					    // this can be re-written as 
					    //	ptr = ptr + 1;
					    //	*ptr;
					    //
			       // ptr now points 3rd element of array 
			       //
			       //
	ptr = &val; //again points first element of array
	

	printf("addr: %p\t data: %d\n",ptr,++*ptr); // this same as ++(*ptr) first dereferencing happens and data inside address gets stored and later data is incremented
						    // instead of 90 91 should print
	

	
	printf("addr: %p\t data: %d\n",ptr,(*ptr)++); // this same a`s ++(*ptr) first dereferencing happens and data inside address gets stored and later data is incremented
						      //
						      //
	printf("data after increment: %d\n",*ptr);
//	printf()
	return 0;
}
