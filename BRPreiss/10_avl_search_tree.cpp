/*
	AVL Search Tree
	g++ -W ./10_avl_search_tree.cpp -o unit_test
*/

#include <iostream>

using namespace std;

/*
	Now node has a height property!
*/
struct Node
{
	Node(int i):left(NULL),right(NULL),context(i),height(-1) {}
	int context;
	Node *left;
	Node *right;
	int height;
};

class AVL[Node]
{
public:
	BST():root(NULL), height(-1) {}
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

	int height();

};

int AVL::height()
{
	return root->height;
}

/*
	just like mark-and-sweep gc algorithm
*/
int AVL::adjustHeight()
{
	if(!root) root->height = -1;
	else
	{
		height = max(root->left->height, root->right->height);
	}
}

int AVL::balanceFactor()
{
	if(!root) return 0;
	else
	{
		return (left->height - right->height);
	}
}

/*
	Four Way To Route
*/
/*
	1. exchange left to right
	2. exchange right->left to left
	3. exchange right->right to right->left
	4. exchange right to right->right
	5. adjust tree height

	When to use:
		left tree is balanced, root tree height-reduce is 1
		insert into left tree
*/
void AVL::LLRotation()
{
	if(!root) return;

	AVLNode * const tmp = root->right;
	root->right = root->left;

	root->left = root->right->left;
	root->right->left = root->right->right;
	root->right->right = tmp;

	root->right->adjustHeight();
	adjustHeight();
}


Node *AVL::find(int i)
{
	return find(i, root);
}

Node *AVL::find(int i, Node *root)
{
	if(root == NULL) return root;

	if(root->context == i) return root;
	else if(root->context > i) return find(i, root->left);
	else return find(i, root->right);
}

Node *AVL::min()
{
	min(root);
}

Node *AVL::min(Node *root)
{
	if(root == NULL) return root;
	if(root->left) return min(root->left);
}

Node *AVL::max()
{
	max(root);
}

Node *AVL::max(Node *root)
{
	if(root == NULL) return root;
	if(root->right) return max(root->right);
}

void AVL::add(int i)
{
	Node *temp = new Node(i);
	add(root, temp);
}

void AVL::add(Node *root, Node *temp)
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

void AVL::swap(Node **n1, Node **n2)
{
	Node *temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void AVL::dec(int i)
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

