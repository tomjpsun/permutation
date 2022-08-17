#ifndef _BAG_H_
#define _BAG_H_


#define BAG_SIZE 32

typedef struct Bag_
{
	int n;
	int bag[BAG_SIZE];
} Bag;

void bag_reset(Bag* pbag);

int take_one_from_bag(Bag* pbag, int index_in_bag);

void dump_bag(Bag* pbag);

void bag_test();

#endif //_BAG_H_
