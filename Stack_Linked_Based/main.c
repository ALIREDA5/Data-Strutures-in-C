/*
 * main.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Ali Reda
 */

#include "stdio.h"
#include "stdlib.h"
#include "Stack.h"

void display(StackEntry e)
{
	printf("%c \n",e);
}

int main(void)
{
	// User Level //
	StackEntry e,c;
	Stack s;
	CreateStack(&s);
	// read element & push it

	scanf("%c",&e);
	fflush(stdout);
	if(! Push(e,&s))
	{
		printf("not able to push");
	}
	// call user defined stack fun
	TraverseStack(&s , &display);
	// pop element & display it
	if(!StackEmbty(&s))
	{
		pop(&c,&s);
	}
	printf("%c \n",c);
	// display stack size
	int size = StackSize(&s);
	printf("%d \n",size);

	return 0;
}


