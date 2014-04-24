/*	
FULL N-TREE:
	inner nodes:	n
	outside nodes:	l
	all nodes:		n+l+1

	n = (n+l-1)/N ==>l = (N-1)n+1

	g++ -W ./08_tree.cpp -o unit_test

	cannot compile successfully

	It is just a math magic, not algorithm.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Relationship
{
public:
	vector<Person *> relationship;
};

struct Person
{
	int age;
	string name;
	int size; 
	vector<Person *> children;
};

/* 
	2/N-TREE 

	linear/non-linear
*/
class Tree: public vector<Person>
{
public:
	Relationship rp;
};

/*
	2-TREE
*/
bool compare_trees(Person *t1, Person *t2)
{
	if(!t1 || !t2) return true;
	if(compare_node(t1, t2)){
		return compare_trees(t1->left, t2->left) && compare_trees(t1->right, t2->right);
	} else {
		return fase;
	}
}

/*
	create a 2-tree from strings

	(2+3)*3-1+5*7

	(+ (- (* (+ 2 3) 3) 1) (* 5 7))

	7 5 * 1 3 3 2 + * - +
*/
Node *magicTree(string a)
{

}

int main(int argc, char const *argv[])
{


	return 0;
}

