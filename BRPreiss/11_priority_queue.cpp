/*
	Priority Queue  --- modeling decrete things
	
	Heap-Tree: Full Binary Tree
	g++ -W ./11_priority_queue.cpp -o unit_test


	zuo yi tree
	er xiang tree
*/

#include <iostream>
#include <vector>
using namespace std;


/*
	Object ==> int
*/
class Priority_Queue
{
public:
	void enqueue(int i);
	int dequeuemin();
	int FindMin();

	vector<int> queue;
};

class BinaryHeap
{
public:
	BinaryHeap() { heap[0] = heap.size();}
	void enqueue(int i);
	int dequeuemin();
	int dequeuemin2();
	int FindMin();

	vector<int> heap;
};

void BinaryHeap::enqueue(int obj)
{
	int count = heap[0];
	++count;

	unsigned int i= count; // root is i/2

	/*
		From end to start --- reverse
		only compare with the [root]
	*/
	while(i>1 && heap[i/2] > obj)
	{
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = obj;
	heap[0] = count;
}

int BinaryHeap::dequeuemin()
{
	/*
		min
	*/
	int result = heap[1];
	int last = heap[heap[0]];

	--count;
	unsigned int i  = 1;

	/*
	*/
	while(2*i < count +1 && 2*i+1 < count +1)
	{
		if(heap[2*i] >= heap[2*i+1])
		{
			if( last < heap[2*i+1])
			{
				heap[i] = last;
				break;
			}
			else
			{
				heap[i] = heap[2*i+1];
				i = 2*i+1;
			}
		}
		else
		{
			if( last < heap[2*i])
			{
				heap[i] = last;
				break;
			}
			else
			{
				heap[i] = heap[2*i];
				i = 2*i;
			}
		}
	}

	if(2*i >= count+1) heap[2*i-1] = last;
	else if (2*i+1 >= count+1) heap[2*i] = last;

	return result;
}


int BinaryHeap::dequeuemin2()
{
	/*
		min
	*/
	int result = heap[1];
	int last = heap[heap[0]];

	--count;
	unsigned int i  = 1;
	unsigned int child = 2*i;
	
	while(child < count+1)
	{
		/*
			Cannot put	child+1 < count+1 in the while condition! 
		*/
		if(child+1 < count+1 && heap[child] >= heap[child+1])
		{
			child = child +1;
		}
		
		if(last <= heap[child]) break;

		heap[i] = heap[child];
		i = child;
	}

	heap[i] = last;
	return result;
}


int main(int argc, char const *argv[])
{



	return 0;
}
