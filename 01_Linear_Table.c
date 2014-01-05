//gcc -W 01_Linear_Table.c -o test

#include <stdio.h>

#define MAXROW 256

struct Row
{
	char *name;
	int age;
	void *prototype; // from javascript
};

// Array
/*****************
  Operations:
	-Add		~O(1)
	-Delete		~O(1)
	-Get		~O(1)
	-Size		~O(1)

	-Find		~O(n)
	-Insert		~O(n)
	-DelOne		~O(n)
	-Clear		~O(n)

******************/
struct LinearTableArray
{
	struct Row elements[MAXROW]; // index: 0~rows-1
	int rows;
};

// Link
/*****************
  Operations:
	-Add		~O(1)
	-Delete		~O(1)
	-Get		~O(1)
	-Size		~O(1)

	-Find		~O(n)
	-Insert		~O(1)
	-DelOne		~O(1)
	-Clear		~O(n)

******************/
struct RowNode
{
	struct Row context;
	struct Row *prev;
	struct Row *next;
};

struct LinearTableLink
{
	struct RowNode *Head;
	struct RowNode *Tail;
	int size;
};

// Hash: use id to replace pointer
// Set:[in]
/*****************
  Operations:
	-Add		~O(m): #hash function
	-Delete		~O(1)
	-Get		~O(1)
	-Size		~O(1)

	-Find		~O(n)
	-Insert		~O(n)
	-DelOne		~O(n)
	-Clear		~O(n)

******************/
struct LinearTableArrayHash
{
	struct Row elements[MAXROW]; // index: 0~rows-1				unique #hash
	int rows;
};

struct LinearTableNodeHash
{
	struct RowNode *elements[MAXROW]; // index: 0~rows-1		size ~ O(n)
	int rows;
};

struct LinearTableNodeLinkHash
{
	struct LinearTableLink *elements[MAXROW]; // index: 0~rows-1 size ~O(1)
	int rows;
};

int main(int argc ,char *argv[])
{

	printf("test!\n");
	return 0;
}

