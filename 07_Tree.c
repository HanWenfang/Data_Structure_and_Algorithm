/****************************************************
 * Index Methods ==> 
 *	Parents Pattern  -- O(1)[Get parent ]
 *	Children Pattern
 *	Pattern & Children Pattern
 *	Children and rightBrother Pattern
 *	Binary Tree Pattern

parent pattern and children pattern are reversed.

 * Binary Tree
	* preorder 
	* inorder
	* postorder
	* level order[FIFO queue]

 * Some IDs
 	* depth: k
 	* max num of tree nodes: 2^k -1
 	* max num of kth level tree nodes: 2^(k-1)
 	* node i --> lower_bound(i/2)
 			 --> left child 2*i (2*i<n)
 			 --> right child 2*i+1 (2*i+1 < n)
*****************************************************/

struct Node{
	char value;
	struct Node *next;
};


int main(int argc, char *argv[])
{
	printf("test!\n");
	return 0;
}










