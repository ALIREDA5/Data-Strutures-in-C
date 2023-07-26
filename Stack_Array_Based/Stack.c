/*
 * Stack.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Ali Reda
 */

#include "Stack.h"

//Implementation level//

//fun to initialize stack
void CreateStack(Stack * ps)
{
	ps->top = 0;
}
// push element to the top of the stack
void push(StackEntry e,Stack * ps)
{
	ps->Entry[ps->top]= e;
	ps->top++;
}
// check if the stack is full or not (to find if if you can push or not)
int fullstack(Stack * ps)
{

	if(ps->top >= MAXSTACK)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// Push fun that had the ability to do the check before pushing
int Push(StackEntry e,Stack * ps)
{
	if(ps->top >= MAXSTACK)
	{
		return 0;
	}
	else
	{
		ps->Entry[ps->top++]= e;
		return 1;
	}
}
// pop element from the position before top
void pop(StackEntry * e,Stack * ps)
{
	*e = ps->Entry[--ps->top];
}
// check if the stack is empty or not (to find if if you can pop or not)
int StackEmbty(Stack * ps)
{
	if(ps->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// Pop fun that had the ability to do the check before Poping
int Pop(StackEntry * e,Stack * ps)
{
	if(ps->top == 0)
	{
		return 0;
	}
	else
	{
		*e = ps->Entry[--ps->top];
		return 1;
	}
}
// fun return size of the stack
int StackSize(Stack * ps)
{
	return ps->top;
}
// fun clear the stack (top = zero)
void StackClear(Stack * ps)
{
	ps->top = 0;
}
// fun to only copy the stack top
void StackCopy(StackEntry *pe, Stack * ps)
{
	*pe = ps->Entry[ps->top - 1];
}
// traverse stack fun
void TraverseStack(Stack * ps , void (*pf)(StackEntry e))
{
	int i;
	for(i= ps->top ; i>0 ; i-- )
		(*pf)(ps->Entry[i-1]);
}










