#include <stdio.h>
#include "stack.h"
#include "string.h"
#include "bag.h"

void perm(Bag bag, Stack* trace)
{
	Bag saved_bag = bag;

	// boundary condition
	if ( bag.n == 0 ) {
		dump_stack(trace);
	}
	// take each ball in the bag in turn
	for (int i=0; i<bag.n; i++) {
		// we have changed the bag, should restore it on next loop
		int ball = take_one_from_bag(&bag, i);
		// record what ball be taken
		push(trace, ball);
		// recursively call perm(), with bag and trace
		perm(bag, trace);
		// restore stack
		pop(trace);
		// restore bag
		bag = saved_bag;
	}
}

int main(int argc, char** argv)
{
	stack_test();
	//bag_test();

	Stack stack;
	Bag bag = { 6, {1,2,3,4,5,6} };

	reset_stack(&stack);
	perm(bag, &stack);

        return 0;
}
