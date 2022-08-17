#include <stdio.h>
#include "stack.h"
#include "string.h"

void reset_stack(Stack* pstk)
{
	memset(pstk, 0, sizeof(Stack));
}

void push (Stack *pstk, int num)
{
	pstk->stack[ (pstk->top)++ ] = num;

	// overflow check
	if ( pstk->top >= MAX_STACK )
		printf("ERROR: push stack full\n");
}

void pop (Stack* pstk)
{
	if ( pstk->top > 0 ) {
		pstk->top --;
	} else {
		// underflow check
		printf("ERROR: pop empty stack\n");
	}
}

int get_top(Stack* pstk)
{
	if ( pstk->top > 0 ) {
		return pstk->stack[ pstk->top - 1 ];
	} else {
		printf("ERROR: get_top with [%d]\n", pstk->top);
		return -1;
	}
}

void dump_stack(Stack* pstk)
{
	printf("dump stack: ");
	for (int i=0; i<pstk->top; i++)
		printf("%d, ", pstk->stack[i]);
	printf("\n");
}

void stack_test()
{
	Stack stack;
	reset_stack(&stack);
	push(&stack, 8);
	printf("stack[%d] is %d\n", stack.top, get_top(&stack));
	push(&stack, 19);
	printf("stack[%d] is %d\n", stack.top, get_top(&stack));
	pop(&stack);
	printf("stack[%d] is %d\n", stack.top, get_top(&stack));
	// 故意多 pop 製造錯誤
	pop(&stack);
	printf("stack[%d] is %d\n", stack.top, get_top(&stack));

}
