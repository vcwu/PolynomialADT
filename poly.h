/*
CS 352, Summer '12
Victoria Wu

Polynomial ADT
-----------------------------------------
The polynomial is represented by a linked list of pairs, each containing
the coefficient and exponents of each term. 
s
-Add, Multiply, Equality functions for polynomials


*/

#include <list>
#include <utility>
using namespace std;

struct term
{
	pair < int, int* > *t;	
	
	term() { t->first = 0; t->second = 0; }
	term(int coeff, int* exp)  
	{
		t->first = coeff; 
		t->second = exp; 
	}
	
	int getCoeff()	{return t->first; }
	int* getExponents()	{return t->second; }
	
};
	
class Poly
{
	private:
		
		list<term> pol;	
		
		Poly simplify(Poly* pol);
		
	public:
		Poly();
		void addTerm(term *t);
		void toString();
		bool equals(const Poly* pol);
		Poly* addPoly(const Poly* pol);
		Poly* multiply(const Poly* pol);
		
		bool equals(const Poly &pol);
		Poly* addPoly(const Poly &pol);
		Poly* multiply(const Poly &pol);
		
};




