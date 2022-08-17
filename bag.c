#include <stdio.h>  // printf()
#include <string.h> // memset()
#include "bag.h"

void bag_reset(Bag* pbag)
{
	memset(pbag, 0, sizeof(Bag));
}


int take_one_from_bag(Bag* pbag, int index_in_bag)
{
	// check index
	if (index_in_bag >= pbag->n) {
		printf("ERROR: index_in_bag %d out of range\n", index_in_bag);
		return -1;
	}
	int result = pbag->bag[ index_in_bag ];
	for (int i = index_in_bag; i < pbag->n - 1; i++)
		pbag->bag[ i ] = pbag->bag[ i+1 ];
	pbag->n -= 1;
	return result;
}

void dump_bag(Bag* pbag)
{
	printf("bag contains %d balls\n", pbag->n);
	for (int i=0; i<pbag->n; i++)
		printf("%d, ", pbag->bag[i]);
	printf("\n");
}

void bag_test()
{
	Bag bag = { 6, {1,2,3,4,5,6} };
	dump_bag(&bag);
        int ball = take_one_from_bag(&bag, 3);
	printf("take ball %d from bag\n", ball);
	// trigger error on boundary
        ball = take_one_from_bag(&bag, 5);
	printf("take ball %d from bag\n", ball);
	ball = take_one_from_bag(&bag, 1);
	printf("take ball %d from bag\n", ball);
	dump_bag(&bag);
}
