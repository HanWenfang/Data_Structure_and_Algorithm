/*
	Hash function should be O(1)
	h1. x % M => h(i) = i
				h(i+1) = i + 1%M
				h(i+2) = i + 2%M 
	Cannot use it as a password hash
	
	h2.
		x<sqrt(W/M)~2^(w-k)
		
	h3.
		a

	h4. fibonacci

	f = g`f
	
	basic hash function ==> hash object

	* HashTable

	g++ -W ./07_hash.cpp -o unit_test
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <list>

#define bitsizeof(T) (8*sizeof(T))

using namespace std;

/*
	%[2^32]
*/
unsigned int const k=10; //M = 1024
unsigned int const w = bitsizeof(unsigned int);

unsigned int hash2(unsigned int x)
{
	return (x*x) >> (w-k);
}

// machine word length
typedef unsigned int HashValue;

HashValue Hash(char c) { return abs(c); }
HashValue Hash(int i) { return abs(i); }
/*
	?
*/
HashValue Hash(double d)
{
	if(d==0) return 0;
	else
	{
		int exponent;
		double mantissa = frexp(d, &exponent);
		return (2*fabs(mantissa) -1);
	}
}

unsigned int const shift = 6;
HashValue const mask = ~0U << (bitsizeof(HashValue) - shift);

HashValue Hash(string const &s)
{
	HashValue result = 0;
	for(unsigned int i=0; i != s.size(); ++i)
		result = (result & mask) | (result << shift)|s[i];
	return result;
}

class Iterator
{
public:
	virtual bool IsDone()  =0;
	virtual int &operator * ()  =0;
	virtual void operator ++() =0;
};

class rIterator : public Iterator
{
public:
	virtual bool IsDone();
	virtual int &operator * ();
	virtual void operator ++();
};

bool rIterator::IsDone(){

}

int &rIterator::operator * (){

}

void rIterator::operator ++(){

}

class row
{
public:
	row():empty(true){}
	bool empty;
	
	vector<int> ints;
	void add(int i){
		ints.push_back(i);
		empty = false;
	}

	rIterator rit;
};

class HashTable : public vector<row>
{
public:
	HashTable(int h) :hash(h) {}
	int hash ;
	void push(int i)
	{
		ints[i%hash].add(i);
	}

	vector<row> ints;

	void print()
	{
		for(vector<row>::iterator it=ints.begin(); it != ints.end(); ++it)
		{
			while((it->rit).IsDone())
			{
				cout << *it->rit;
				++it->rit;
			}
			cout <<endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	vector< list<int> > ints;
	ints.reserve(10);
	/*
	if(ints[0].empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << *ints[0].begin() << endl;
	}
	*/
	return 0;
}

