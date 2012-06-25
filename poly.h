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
#include <iostream>
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

	int getExp(int i) const {return exp[i];}

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

	friend ostream& operator<<(ostream& out, const term &t)
	{
		out <<t.coeff;

		if ( !(t.exp[0] ==0 ))
		{
			out << "x";
			if(t.exp[0] >1)
				out << "^" <<  t.exp[0];
		}
		if ( !(t.exp[1] == 0))
		{
			out << "y";
			if(t.exp[1] >1)
				out << "^" <<t.exp[1];
		}

		return out;
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

	static bool equalExponents(term t1, term t2)
	{
		if(t1.exp[0] == t2.exp[0])
			if(t1.exp[1] == t2.exp[1])
				return true;
		return false;
	}

	static term multiply(term t1, term t2)
	{
		int newC = t1.coeff*t2.coeff;
		int newExp1 = t1.exp[0]+t2.exp[0];
		int newExp2 = t1.exp[1]+t2.exp[1];
		return term(newC, newExp1, newExp2);
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
		list<term>* getTerms()  { return &allTerms;}
		void addTerm(int coeff, int exp1, int exp2);
		void addTerm(term t);
		friend ostream& operator<<(ostream& out, const Poly &poly);
		
		
		//I wonder if I can make this static...
		list<term>* simplify();

		Poly* evaluate(const Poly &pol);

		bool isEmpty() const;
		bool equals(Poly &poly1, Poly &poly2);
		Poly* addPoly(Poly &poly1, Poly &poly2);
		Poly* multiply(Poly &poly1, Poly &poly2);
		
		
		//evaluate
		//--> Will evalaute for number input,
		//then map x and y to first, second

		
};




