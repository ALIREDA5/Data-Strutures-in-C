/*
 * main.c
 *
 *  Created on: Aug 2, 2023
 *      Author: Ali Reda
 */

#include "stdio.h"
#include "Stack.h"

void InfixToPostfix(char infix[], char postfix[])
{
	int i, j;
	char op, c;
	Stack s;
	CreatStack(&s);
	for(i=0, j=0; (c=infix[i]!='\0'); i++)
	{
		if(IsDigit(c))
			postfix[j++]=c;
		else{
			if(!StackEmbty(&s))
			{
				StackTop(&op, &s);
				while(!StackEmbty(&s) && precedent(op, c))
				{
					pop(&op, &s);
					postfix(j++)=op;
					if(!StackEmbty(&s)) 	StackTop(&op, &s);
				}
			}
			push(c, &s);
		}
		while(!StackEmbty(&s))
		{
			pop(&op, &s);
			postfix(j++)=op;
		}
		postfix[j]='\0';
	}
}

int main(void){









	return 0;
}
