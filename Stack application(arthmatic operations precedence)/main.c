/*
 * main.c
 *
 *  Created on: Aug 2, 2023
 *      Author: Ali Reda
 */

#include "stdio.h"
#include "Stack.h"
#include "Math.h"

/* limitations
 * 1. only single digit integers
 * 2. only positive integers
 * 3. no unary operators (Ex. -3)
 * 4. no brackets
 * 5. no handling for invalid expression
 */

/*
 * rewrite it to account for as much limitations as you can
 */

int IsDigit(char c)
{
	if(c>='0' && c<='9')
		return 1;
	else
		return 0;
}

int precedent(char op1, char op2)
{
	// power has precedence more than any other operator
	if(op1=='$') return 1;
	// mul and div has precedence over + -
	if(op1=='*' || op1=='/')
		return op2!='$';
	// add and sub
	if(op1=='+' || op1=='-')
		return (op2!='$')&&(op2!='*')&&(op2!='/');
	return 0;
}/*
void InfixToPostfix(char infix[], char postfix[])
{
	int i, j;
	char op, c;
	Stack s;
	CreateStack(&s);
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
					postfix[j++]=op;
					if(!StackEmbty(&s)) StackTop(&op, &s);
				}
			}
			push(c, &s);
		}
		while(!StackEmbty(&s))
		{
			pop(&op, &s);
			postfix[j++]=op;
		}
		postfix[j]='\0';
	}
}
*/
double oper(char c, int op1, int op2)
{
	double x;
	switch(c)
	{
	case '+':  x=(op1+op2);  break;
	case '-':  x=(op1-op2);  break;
	case '*':  x=(op1*op2);  break;
	case '/':  x=(op1/op2);  break;
	case '$':  x=(pow(op1,op2)); break;
	}
	return x;
}
double EvaluatePostfix(char expr[])
{
	int i;
	double op1, op2;
	double val;
	char c;
	Stack s;
	CreateStack(&s);
	for(i=0 ; (c=expr[i])!='\0' ; i++)
	{
		if(IsDigit(c))
			push((double)(c-'0'), &s);
		else{
			pop(&op2, &s);
			pop(&op1, &s);
			val=oper(c, op1, op2);
			push(val, &s);
		}
	}
	pop(&val, &s);
	return val;
}

int main(void){









	return 0;
}
