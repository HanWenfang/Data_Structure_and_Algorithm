#include <stdio.h>

#define MAXROW 256

//Shared Stack [- -]
struct SharedStack
{
	struct Row elements[MAXROW]; // index: 0~rows-1
	int ltop; // starts with 0
	int rtop; // starts with MAXROW-1
};

int isEmpty(struct SharedStack *s){
	return ltop == 0 && rtop == MAXROW-1;
}

int isFull(struct SharedStack *s){
	return ltop == rtop;
}


int main(int argc, char *argv[])
{
	printf("test!\n");
	return 0;
}h



