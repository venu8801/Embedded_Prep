/* 1) Byte-Packing Stack.
WTD: Design a stack that efficiently stores 8-bit data in a continuous memory space.
Ensure that the 32-bit words are packed without any wastage.
(e.g: I/P: Push 0x01, 0x02, 0x03, 0x04 ; O/P: Memory content - 0x04030201) */


#include <stdio_ext.h>
#define MAX 15 // 0 to 15 groups of 8bit data (1 byte)

unsigned int byteStack[4] = {0};  //byte stack which can store 16 bytes data 
int idx = -1;
typedef unsigned char u8_t;

void push(u8_t data){

	if(idx == MAX){ //if stack is full return
		printf("Stack is full\n");
		return;
	}
	idx++; //incrementing index9
	byteStack = ( byteStack[] | (data << (idx/4)*8) );
	if(idx>3){idx=0;}
	return;
	
}


void display(){

	if(idx == -1){
		printf("stack is empty\n");
		return;
	}
	int i;
	for(i = 0; i <= idx; i++)
	{
		printf("0x%x ",(byteStack[i % 4] & (0xFF<< i*8)) );
		

	}


}


int main(){
	int opt,data;

	while(1){
		printf("Select a option: \n");
		printf("1.Push \n2.Display\n3.Exit\n");
		__fpurge(stdin);
		scanf("%d",&opt);
		switch(opt)
		{	
			case 1:
				printf("-------------push operation-------\n");
				printf("Enter data :");
				scanf("%x",&data);
				break;
			case 2:
				printf("------------Displaying all nodes-----------\n");
				display();
				break;
			default:
				printf("Option not present\n");
				break;

		}


	}

	return 0;
}


