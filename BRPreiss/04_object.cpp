/*
	abstract the hard way
	nullobject
	containerobject :iterator
	visitor
	ownership

	g++ -W ./04_object.cpp -o unit_test
*/
#include <iostream>
#include <typeinfo>

using namespace std;

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

class nullobject : public object
{
public:

	static nullobject instance;

	int CompareTo(object const &r) const { return 0;};

	nullobject() {};
	bool IsNull() { return true; }
	//virtual HashValue Hash() = 0;
	void Put(ostream &s) const
	{
		s<<"NullObject";
	};
	static nullobject &Instance()
	{
		return instance;
	}
};

template<class T>
class wrapper : public object
{
public:
	T data;
	int CompareTo(T const &) const;

	wrapper();
	wrapper(T const &);
	wrapper & operator = (T const &);

	//functor
	operator T const & () const { return data; }

	void Put(ostream &) const;
};

class visitor
{
public:
	virtual void visit(object &) =0;
	virtual bool IsDone() const { return false; }
};

// composition relation
class Iterator
{
public:
	virtual ~Iterator();
	virtual void reset() = 0;
	virtual bool IsDone() const =0;
	virtual object &operator * () const =0;
	virtual void operator ++() =0;
};

int main(int argc, char const *argv[])
{
	nullobject anull;

	anull.Put(cout);
	cout <<endl;
	return 0;
}



