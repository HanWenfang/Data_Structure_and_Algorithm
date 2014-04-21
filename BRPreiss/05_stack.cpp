/*
	stack
	g++ -W ./05_stack.cpp -o unit_test	
*/
#include <iostream>
#include <typeinfo>
#include <stdexcept>

using namespace std;
using std::out_of_range;

class object
{
public:
	virtual int CompareTo(object const &r) const=0;

	virtual ~object();
	virtual bool IsNull();
	virtual int Compare(object const &r) const;
	//virtual HashValue Hash() = 0;
	virtual void Put(ostream &) const = 0;
};

object::~object() {}

bool object::IsNull()
{
	return false;
}

int object::Compare(object const &r) const
{
	if(typeid(*this) == typeid(object))
		return CompareTo(r);
	else if (typeid(*this).before(typeid(r)))
		return -1;
	else
		return 1;
}

inline bool operator == (object const &left, object const &right){
	return left.Compare(right) == 0;
}

inline bool operator != (object const &left, object const &right){
	return left.Compare(right) != 0;
}

inline bool operator <= (object const &left, object const &right){
	return left.Compare(right) <= 0;
}

inline bool operator >= (object const &left, object const &right){
	return left.Compare(right) >= 0;
}

inline bool operator < (object const &left, object const &right){
	return left.Compare(right) < 0;
}

inline bool operator > (object const &left, object const &right){
	return left.Compare(right) > 0;
}

inline ostream &operator << (ostream &s, object const &obj){
	obj.Put(s);
	return s;
}

template <class T>
class array
{
public:
	array();
	array(unsigned int len, unsigned int ba);
	~array();

	array(array const &);
	array &operator = (array const &);

	T const &operator [] (unsigned int) const;
	T &operator [] (unsigned int);

	T const *Data() const;
	unsigned int Base() const;
	unsigned int Length() const;

	void SetBase(unsigned int);
	void SetLength(unsigned int);

//private:
	unsigned int length;
	unsigned int base;
	T *data;
};

template<class T>
array<T>::array():data(NULL), base(0), length(0)
{

}

template<class T>
array<T>::array(unsigned int len, unsigned int ba):data(new T[len]), base(ba), length(len)
{

}

template<class T>
array<T>::array( array<T> const &arr):data(new T[arr.length]), base(arr.base), length(arr.length)
{
	for(unsigned int i=0; i<length; ++i)
	{
		data[i] = arr.data[i];
	}
}

template<class T>
array<T>::~array()
{
	delete[] data;
}

template<class T>
T const *array<T>::Data() const
{
	return data;
}

template<class T>
unsigned int array<T>::Base() const
{
	return base;
}

template<class T>
unsigned int array<T>::Length() const
{
	return length;
}

template<class T>
T const &array<T>::operator[] (unsigned int position) const
{
	unsigned int const offset = position - base;
	if(offset > length)
	{
		throw out_of_range("invalid position");
	}
	return data[offset];
}

template<class T>
T  &array<T>::operator[] (unsigned int position)
{
	unsigned int const offset = position - base;
	if(offset > length)
	{
		throw out_of_range("invalid position");
	}
	return data[offset];
}

template<class T>
array<T> &array<T>::operator = (array const &rharray)
{
	if(&rharray == this) return *this;
	
	if(data != NULL) delete[] data;

	length = rharray.length;
	base = rharray.base;
	data = new T[length];

	for(unsigned int i=0; i<length; ++i)
	{
		data[i] = rharray.data[i];
	} 

	return *this;
}

template<class T>
void array<T>::SetBase(unsigned int newbase)
{
	base = newbase;
}

template<class T>
void array<T>::SetLength(unsigned int newLength)
{
	T *const newData = new T[newLength];
	unsigned int const min = length>newLength ? newLength:length;

	for(int i=0; i<min; ++i)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	length = newLength;
}

/*
	Do we need a GC?
	Never use pointer?

	lisp/stack 
*/
class stack
{
public:
	array<object *> arrays; // A reference doesn't have a pointer

	void push(object &obj); 
	object &pop(); // nullobject
	int top;

	//class Iterator;
};

class queue
{
public:
	virtual void enqueue(object &);
	virtual void dequeue(object &);

	/*
		detail implementation
			circular array 
			

	*/
	array<object *> arrays;
	int arraylength;
	/*
		switch empty
			case head == tail
			case head == tail -1

		switch full:
			case count == arraylength
			case head == tail
	*/

	unsigned int head;
	unsigned int tail;
};


int main(int argc, char const *argv[])
{



	return 0;
}

