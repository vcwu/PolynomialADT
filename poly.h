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

	int coeff;
	int exp[2];

	

	term() { coeff = 0; exp[0] = 0; exp[1] = 0;}
	term(int c, int exp1, int exp2)  
	{
		coeff = c; 
		exp[0] = exp1; 
		exp[1] = exp2;
	}
	
	int getCoeff() const {return coeff; }

	int getExp1() const {return exp[0];}
	int getExp2() const {return exp[1];}

	friend bool operator<  (term t1, term t2)
	{
		if ( t1.exp[0] < t2.exp[0])
			return true;
		if ( t1.exp[0] > t2.exp[0])
			return false;
		
		//if exp[0] of both are ==
		if ( t1.exp[1] < t2.exp[1])
			return true;
		if ( t1.exp[1] > t2.exp[1])
			return false;
		 
		
		return false;
	}

	friend bool operator== (term t1, term t2)
	{
			if(t1.exp[0] == t2.exp[0])
				if(t1.exp[1] == t2.exp[1])
					return true;
		return false;
	}

	/*
	friend bool operator >  (term t1, term t2)
	{
		if( t1.exp[0] )
	}
	*/
};
	
class Poly
{

	private:
		
		list<term>  allTerms;	
		
		
	public:
		
		Poly() {}
		Poly(list<term> p) { allTerms = p;}
		list<term>* getTerms() { return &allTerms;}
		void addTerm(int coeff, int exp1, int exp2);
		friend ostream& operator<<(ostream& out, const Poly &poly);
		
		
		
		list<term>* simplify(list<term>*  p, int x, int y);

		Poly* evaluate(const Poly &pol);

		bool isEmpty() const;
		bool equals(Poly &poly1, Poly &poly2);
		Poly* addPoly(const Poly &pol);
		Poly* multiply(const Poly &pol);
		
		
		//evaluate
		//--> Will evalaute for number input,
		//then map x and y to first, second

		
};




