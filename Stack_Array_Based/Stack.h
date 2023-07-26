/*
 * Stack.h
 *
 *  Created on: Jul 26, 2023
 *      Author: Ali Reda
 */

#ifndef STACK_H_
#define STACK_H_

#define  MAXSTACK  100
typedef   char   StackEntry;

typedef struct stack
{
	int top;
	StackEntry  Entry[MAXSTACK];
}Stack;

void CreateStack(Stack * ps);
void push(StackEntry e,Stack * ps);
int fullstack(Stack * ps);
int Push(StackEntry e,Stack * ps);
void pop(StackEntry * e,Stack * ps);
int StackEmbty(Stack * ps);
int Pop(StackEntry * e,Stack * ps);
int StackSize(Stack * ps);
void StackClear(Stack * ps);
void StackCopy(StackEntry *pe, Stack * ps);
void TraverseStack(Stack * ps , void (*pf)(StackEntry e));

#endif /* STACK_H_ */
