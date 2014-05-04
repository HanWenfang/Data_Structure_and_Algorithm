/*
	1. M-way search tree
	2. 2-way search tree [ unique node ] chose a better middle node
		in-order-search: middle-order-search

	
	g++ -W ./09_search_tree.cpp -o unit_test
*/
#include <iostream>

using namespace std;

struct Node
{
	Node(int i):left(NULL),right(NULL),context(i) {}
	int context;
	Node *left;
	Node *right;
};

class BST
{
public:
	BST():root(NULL) {}
	~BST() {
		/*
			remember to release the memory
		*/
	}
	void add(int i);
	void add(Node *root, Node *temp);

	void dec(int i);
	void balance();
	Node *find(int i);
	Node *find(int i, Node *root);
	
	Node *min();
	Node *min(Node *root);
	Node *max();
	Node *max(Node *root);

	void swap(Node **n1, Node **n2);

	Node *root;
};

Node *BST::find(int i)
{
	return find(i, root);
}

Node *BST::find(int i, Node *root)
{
	if(root == NULL) return root;

	if(root->context == i) return root;
	else if(root->context > i) return find(i, root->left);
	else return find(i, root->right);
}

Node *BST::min()
{
	min(root);
}

Node *BST::min(Node *root)
{
	if(root == NULL) return root;
	if(root->left) return min(root->left);
}

Node *BST::max()
{
	max(root);
}

Node *BST::max(Node *root)
{
	if(root == NULL) return root;
	if(root->right) return max(root->right);
}

void BST::add(int i)
{
	Node *temp = new Node(i);
	add(root, temp);
}

void BST::add(Node *root, Node *temp)
{	
	if(root == NULL){
		root = temp;
		return;
	}
	
	if(root->context > temp->context) 
	{
		add(root->left, temp);
	}
	else if(root->context < temp->context)
	{
		add(root->right, temp);
	} 

	return;
}

void BST::swap(Node **n1, Node **n2)
{
	Node *temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void BST::dec(int i)
{
	Node *needtodel = find(i, root);

	if(needtodel->left == NULL && needtodel->right == NULL){
		delete needtodel;
		return;
	} else if(needtodel->left != NULL && needtodel->right == NULL) {
		Node *maxleft = max(needtodel->left);
		swap(&needtodel, &maxleft);
		delete needtodel;
		return;
	} else if(needtodel->left == NULL && needtodel->right != NULL) {
		Node *minright = min(needtodel->right);
		swap(&needtodel, &minright);
		delete needtodel;
		return;
	} else {
		/*
			needtodel->left != NULL && needtodel->right != NULL

			right? or left?
		*/

		Node *minright = min(needtodel->right);
		Node *maxleft = max(needtodel->right);

	}

}

int main(int argc, char const *argv[])
{


	return 0;
}

