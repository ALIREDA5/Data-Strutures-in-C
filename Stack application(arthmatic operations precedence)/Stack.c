/*
 * Stack.c
 *
 *  Created on: Aug 2, 2023
 *      Author: Ali Reda
 */


#include "stdio.h"
#include  "stdlib.h"
#include "Stack.h"

//Implementation level//

//fun to initialize stack
void CreateStack(Stack * ps)
{
	ps->top = NULL;
}
// push element to the top of the stack
void push(StackEntry e,Stack * ps)
{
	StackNode *pn = (StackNode *)(malloc(sizeof(StackNode)));
	pn->next=ps->top;
	pn->entry=e;
	ps->top=pn;
}
// check if the stack is full or not (to find if if you can push or not)
int fullstack(Stack * ps)
{
	return 0;
}

// pop element from the position before top
void pop(StackEntry * e,Stack * ps)
{
	StackNode *pn;
	*e = ps->top->entry;
	pn=ps->top;
	ps->top=pn->next;
	free(pn);

}
// check if the stack is empty or not (to find if if you can pop or not)
int StackEmbty(Stack * ps)
{
	return (ps->top == NULL);
}
// Pop fun that had the ability to do the check before Poping

// fun return size of the stack
int StackSize(Stack * ps)
{
	int size=0;
	StackNode *pn=ps->top;
		while(pn){
			size++;
			pn=pn->next;
		}
		return size;
}
// fun clear the stack (top = zero)
void StackClear(Stack * ps)
{
	StackNode *pn=ps->top;
	while(pn){
		pn=pn->next;
		free(ps->top);
		ps->top=pn;
	}

}
// fun to only copy the stack top
void StackTop(StackEntry *pe, Stack * ps)
{
	*pe = ps->top->entry;

}
// traverse stack fun
void TraverseStack(Stack * ps , void (*pf)(StackEntry e))
{
	StackNode *pn=ps->top;
		while(pn){
			(*pf)(pn->entry);
			pn=pn->next;
		}
}


