/***************************
 
 page number number counter

 0  1  2  3  4  5  6  7  8  9
 10 11 12 13 14 15 16 17 18 19
 20 21 22 23 24 25 26 27 28 29
 30 31 32 33 34 35 36 37 38 39
 40 41 42 43 44 45 46 47 48 49
 50 51 52 53 54 55 56 57 58 59
 60 61 62 63 64 65 66 67 68 69
 70 71 72 73 74 75 76 77 78 79
 80 81 82 83 84 85 86 87 88 89
 90 91 92 93 94 95 96 97 98 99

g++ -W number_counter.cpp -o test
***************************/
#include <iostream>
#include <string.h>

using namespace std;

// forced-algo
void counter_1(int pages, int *numbers)
{
	int temp;
	for(int i=pages; i>=0; --i){
		temp = i;
		while(temp){
			++numbers[temp%10];
			temp /= 10;
		}
	}
	++numbers[0];
}

/***********************
 recursive formula:

			/ 10*f(n-1) + 10^n-1  n>1
	f(n) = 
			\ 1 		n=1

************************/
void counter_2(int pages, int *numbers)
{


}

void print(int *numbers)
{
	for(int i=0; i <10; ++i)
	{
		cout << i << ": " << numbers[i] << endl;
	}
}

void init(int s, int *numbers)
{
	for(int i=0; i <10; ++i)
	{
		numbers[i] = s;
	}
}

int main(int argc, char const *argv[])
{
	int numbers[10];
	init(0, numbers);
	cout << sizeof(numbers) << endl;
	int pages = 2999;
	counter_1(pages, numbers);
	print(numbers);

	return 0;
}






