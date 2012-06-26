/*
CS 352, Summer '12
Victoria Wu

Polynomial ADT
-----------------------------------------
The polynomial is represented by a linked list of terms, each containing
the coefficient and exponents of each term. 

-Add, Multiply, Equality functions for polynomials


*/

#include <list>
#include <utility>
#include <iostream>
#include <string>

using namespace std;

struct term
{

	int coeff;
	int exp[2];
	//string values is to for purpose of printing out the correct variable.
	string val1, val2;

	term() { coeff = 0; exp[0] = 0; exp[1] = 0; 
		 val1 = "x", val2 = "y";}

	term(int c, int exp1, int exp2, string v1 = "x", string v2 = "y")  
	{
		coeff = c; 
		exp[0] = exp1; 
		exp[1] = exp2;
		val1 = v1; 
		val2 = v2;
	}
	~term() { }
	void swap()
	{
		int temp = exp[0];
		exp[0] = exp[1];
		exp[1] = temp;
		string temp2 = val1;
		val1 = val2;
		val2 = temp2;

	}

	int getCoeff() const {return coeff; }

	int getExp(int i) const {return exp[--i];}

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
				out  <<  t.exp[0];
		}
		if ( !(t.exp[1] == 0))
		{
			out << "y";
			if(t.exp[1] >1)
				out <<t.exp[1];
		}

		return out;
	}
	/*
	This tests if the terms are exactly equal (coeff and exps).
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

	term& term::operator= (const term &rhs)
	{
		if (this == &rhs)
			return *this;
		coeff = rhs.getCoeff();
		exp[0] = rhs.getExp(1);
		exp[1] = rhs.getExp(2);
		val1 = rhs.val1;
		val2 = rhs.val2;

		return *this;
	}
};
	
class Poly
{

	private:
		list<term>  allTerms;	
		
		
	public:
		Poly() {}
		~Poly() { }
		Poly(list<term> *p) { allTerms = *p;}

		//Setters, Getters
		void setTerms(list<term> *p) {allTerms = *p;}
		list<term>* getTerms() { return &allTerms;}
		void addTerm(int coeff, int exp1, int exp2);
		void addTerm(term t);
		bool isEmpty() const;
		friend ostream& operator<<(ostream& out, const Poly &poly);

		//Do stuff with Polynomials
		list<term>* simplify();
		bool equals(Poly &poly1, Poly &poly2);
		Poly* addPoly(Poly &poly1, Poly &poly2);
		Poly* multiply(Poly &poly1, Poly &poly2);

		//For Testing Complexity
		long simplifyTester();
		long addPolyTest(Poly &poly1, Poly &poly2);
		long equalsTester(Poly &poly1, Poly &poly2);
		long multiplyTester(Poly &poly1, Poly &poly2);
		
};




