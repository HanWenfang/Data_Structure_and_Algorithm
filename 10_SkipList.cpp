/*******************************************************
 * Ordered Link-List for INDEX in place of balanced tree
 * Reference : kenby.iteye.com/blog/1187303
 			   igoro.com/archive/skip-lists-are-fascinating
 * -Unique Key-
 * A kind of Data Structure has many kinds of implementation ways!!
 *
********************************************************/
class Node
{
public:
	Node(int key):value(key), next(NULL) {}
	Node *next;
	int value;
};

class Nodes
{
public:
	Nodes(int key, int level)
	{
		value = key;
		root = new Node(key)[level];
		next = NULL;
	}

	int value;
	Node *root;
	Nodes *next;
};

class IntSkipList
{
public:
	Nodes *head = new Nodes(0, 20); // value = 0[min] Head doesn't contain value!
	levels = 1;

	bool contain(int value)
	{
		Nodes *cur = head;
		for(int i=levels-1; i>=0; --i) // level
		{
			for(;cur->root[i]->next != NULL; cur = cur->next) // list
			{
				if(cur->root[i]->next->value > value) break;
				if(cur->root[i]->next->value == value) return true;
			}
		}
		return false;
	}


};

int main(int argc, char *argv[])
{




	return 0;
}



