#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>

#define MAX_STACK  128

typedef struct _Stack {
	int top;
	int stack[MAX_STACK];
} Stack;

void reset_stack(Stack* pstk);

void push (Stack *pstk, int num);

void pop (Stack* pstk);

int get_top(Stack* pstk);

void dump_stack(Stack *pstk);

void stack_test();


#endif //_STACK_H_
