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

	static bool equalExponents(term t1, term t2)
	{
		if(t1.exp[0] == t2.exp[0])
			if(t1.exp[1] == t2.exp[1])
				return true;
		return false;
	}

	/*
	This tests if the terms are exactly equal (coeff, exps).
	*/
	friend bool operator== (term t1, term t2)
	{
		if(equalExponents(t1,t2))
			if(t1.coeff == t2.coeff)
				return true;
		return false;
	}


};
	
class Poly
{

	private:
		
		list<term>  allTerms;	
		
		
	public:
		
		//do i need a destructor?


		Poly() {}
		Poly(list<term> *p) { allTerms = *p;}
		list<term>* getTerms() { return &allTerms;}
		void addTerm(int coeff, int exp1, int exp2);
		friend ostream& operator<<(ostream& out, const Poly &poly);
		
		
		//I wonder if I can make this static...
		list<term>* simplify();

		Poly* evaluate(const Poly &pol);

		bool isEmpty() const;
		bool equals(Poly &poly1, Poly &poly2);
		Poly* addPoly(Poly &poly1, Poly &poly2);
		Poly* multiply(const Poly &pol);
		
		
		//evaluate
		//--> Will evalaute for number input,
		//then map x and y to first, second

		
};




