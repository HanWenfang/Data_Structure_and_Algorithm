
//binary search
// reference: my.oschina.net/fullofbull/blog.199693#OSC_h4_1
// more : blog.csdn.net/luckyxiaoqiang/article/details/8937978
// more : loop invariant: www.douban.com/note/300378458  [ Programming Pearls ]

// open interval / closed interval / half open interval / half closed interval

#include <iostream>

using namespace std;

// integer_set: sorted set [ no repetation ]

int binary_search(int *integer_set, int size, int target)
{
	int low = 0;
	int high = size-1;
	int mid;

	while(low <= high)
	{
		mid = low + (high-low)/2;

		if(integer_set[mid] == target) 
			return mid;
		else if( integer_set[mid] < target) 
			low = mid+1;
		else
			high = mid-1;
	}
	return -1;
}

// sorted [ repetation ] - the smallest index
int binary_search_first_position(int *integer_set, int size, int target)
{
		int low = 0;
		int high = size;
		int mid;

		while(low < high)
		{
			mid = low + (high-low)/2;

			if(integer_set[mid] < target) 
				low = mid+1;
			else //integer_set[mid] >= target
				high = mid;
		}
		
		if(low >= size || integer_set[low] != target)
			return -1;
		else
			return low;
}

// sorted [ repetation ] - the largest index
int binary_search_last_position(int *integer_set, int size, int target)
{
		int low = -1;
		int high = n-1;
		int mid;

		while(low < high)
		{
			mid = high - (high-low)/2;

			if(integer_set[mid] > target) 
				high = mid -1;
			else //integer_set[mid] >= target
				low = mid;
		}
		
		if(high < 0 || integer_set[high] != target)
			return -1;
		else
			return high;
}




int main(int argc, char *argv[])
{
	int integer_set[10] = {20,21,22,23,24,25,26,27,28,29};

	cout << binary_search(integer_set, 10, 25) << endl;

	return 0;
}

