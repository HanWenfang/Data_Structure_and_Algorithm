/*
	use vector to represent a poly

	g++ -W ./06_polynomial.cpp -o unit_test
	
	There is no sorted_vector, sorted_list etc. in C++ STL.
	Sort is a general algorithm, STL provited a sort function to sort STL "object".
*/

#include <iostream>
#include <vector>

using namespace std;

class Term
{
public:
	double coefficient;
	unsigned int exponent;

	Term(double co, unsigned int exp);
	void differentiate();

	int CompareTo(Term const &term) const;
};

Term::Term(double co, unsigned int exp):coefficient(co), exponent(exp) {}

void Term::differentiate()
{
	if(exponent > 0)
	{
		coefficient *= exponent;
		--exponent;
	}
	else
	{
		coefficient = 0;
	}
}

int Term::CompareTo(Term const &term) const
{
	if(exponent == term.exponent)
	{
		if(coefficient == term.coefficient)
			return 0;
		else
			return coefficient > term.coefficient? 1:-1;
	}
	else
	{
		return exponent > term.exponent? 1:-1;
	}
}

class Polynomial : public vector<Term>
{
public:
	void differentiate()
	{
		for(vector<Term>::iterator it=begin(); it != end(); ++it)
		{
			it->differentiate();
		}
	}

	void print()
	{
		for(vector<Term>::iterator it=begin(); it != end(); ++it)
		{
			cout << "(" << it->coefficient << ", " << it->exponent << " )";
		}

		cout << endl;
	}

};

int main(int argc, char const *argv[])
{
	Term term1(3,4);
	Term term2(3,2);
	Term term3(3,3);
	Term term4(3,7);
	Polynomial poly;

	poly.push_back(term1);
	poly.push_back(term2);
	poly.push_back(term3);
	poly.push_back(term4);

	poly.print();

	poly.differentiate();

	poly.print();


	return 0;
}





