/*
	Basic Store Structure

	list type should be the first-class type in cpp.
	list<>

	g++ -W ./03_list.cpp -o unit_test
*/
#include <iostream>
#include <stdexcept>

using std::out_of_range;
using std::domain_error;
using namespace std;

template <class T>
class linkedlist;

template <class T>
class listelement
{
public:
	T const& datum() const;
	
	T data;
	listelement *next;
	listelement(T const &, listelement *);
};

template <class T>
listelement<T>::listelement(T const &_datum, listelement *_next):data(_datum), next(_next)
{}

// O(1) return reference!
template <class T>
T const& listelement<T>::datum() const
{
	return data;
}


/*
	switch node:
		case head:
		case tail:
*/

template <class T>
class linkedlist
{
public:
	linkedlist();
	~linkedlist();

	linkedlist(linkedlist const &);
	linkedlist<T> &operator = (linkedlist const &);

	listelement<T> *Head() const;
	listelement<T> *Tail() const;

	bool IsEmpty();
	T const &first() const;
	T const &last() const;

	void prepend(T const &);
	void append(T const &);
	void extract(T const &);
	void purge();
	void insertafter(listelement<T> *, T &);
	void insertbefore(listelement<T> *, T &);

//private:
	listelement<T> *head;
	listelement<T> *tail;
};

/*
	delete one node whose context is item
*/
template<class T>
void linkedlist<T>::extract(T const &item)
{
	listelement<T> *temp1 = head;
	listelement<T> *prevtemp1 = NULL;
	while(temp1 != NULL && temp1->datum() != item)
	{
		prevtemp1 = temp1;
		temp1 = temp1->next;
	}

	if(temp1 != NULL)
	{
		if(temp1 == head) {
			head = head->next;
		} 

		if(temp1 == tail) {
			tail = prevtemp1;
		}

		if(temp1 != head && temp1 != tail) {
			prevtemp1->next = temp1->next;
		}

		delete temp1;
	}
}

template<class T>
void linkedlist<T>::insertafter(listelement<T> *node, T &item)
{
	if(node==NULL) return;
	listelement<T> *temp = new listelement<T>(item, node->next);
	node->next = temp;

	if(node == tail)
		tail = temp;
}

template<class T>
void linkedlist<T>::insertbefore(listelement<T> *node, T &item)
{
	if(node == NULL) return;
	listelement<T> *temp = new listelement<T>(item, node);

	if(node == head)
		head = temp;
	else
	{
		listelement<T> *prevnode = head;
		while(prevnode->next && prevnode->next != node)
			prevnode = prevnode->next;
		
		if(prevnode->next != NULL)
		{
			prevnode->next = temp;
		}
	}
}

template<class T>
linkedlist<T>::linkedlist():head(NULL), tail(NULL)
{}

template<class T>
linkedlist<T>::linkedlist( linkedlist<T> const &linlist):head(NULL), tail(NULL)
{
	listelement<T> *temp;
	for(temp = linlist->head; temp != NULL; temp = temp->next)
	{
		append(temp->datum());
	}
}

template<class T>
linkedlist<T>::~linkedlist()
{
	purge();
}

template<class T>
void linkedlist<T>::purge()
{
	listelement<T> *temp;
	while(head != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	tail = NULL;
}

template<class T>
listelement<T> *linkedlist<T>::Head() const
{
	return head;
}

template<class T>
listelement<T> *linkedlist<T>::Tail() const
{
	return tail;
}

template<class T>
bool linkedlist<T>::IsEmpty()
{
	return head==NULL;
}

template<class T>
T const &linkedlist<T>::first() const
{
	if(head == NULL) {
		throw domain_error("list is empty");
	}

	return head->datum();
}

template<class T>
T const &linkedlist<T>::last() const
{
	if(tail == NULL) {
		throw domain_error("list is empty");
	}

	return tail->datum();
}

template<class T>
void linkedlist<T>::prepend(T const &_datum)
{
	listelement<T> *temp = new listelement<T>(_datum, head);
	if(head == NULL) tail = temp;

	head = temp;
}

template<class T>
void linkedlist<T>::append(T const &_datum)
{
	listelement<T> *temp = new listelement<T>(_datum, NULL);
	if(tail == NULL) head = temp;
	else
	{
		tail->next = temp;
	}

	tail = temp;
}

template<class T>
linkedlist<T> &linkedlist<T>::operator = (linkedlist const &rhlinkedlist)
{
	if(&rhlinkedlist == this) return *this;
	
	purge();

	listelement<T> *temp;
	for(temp = rhlinkedlist-> head; temp != NULL; temp = temp->next)
	{
		append(temp->datum());
	}

	return *this;
}


int main(int argc, char const *argv[])
{
	linkedlist<int> la;
	la.append(12);
	la.append(13);
	la.append(14);

	int a=11;
	la.insertbefore(la.Head(),a);

	return 0;
}

