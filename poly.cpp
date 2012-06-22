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

#include "poly.h"
#include <string>
#include <iostream>
using namespace std;

void Poly::addTerm(int coeff, int exp1, int exp2)
{	
	term t(coeff, exp1, exp2);
	pol.push_front(t);
}

ostream& Poly::operator<<(const Poly &poly)
{
	list<term>::iterator it;
	string meat;
	
	for(it = pol.begin(); it != pol.end(); ++it)
	{
		//fluff to print out one term
	}
	
	return cout << meat;
}

/*
	The two polynomials will be added together, then simplified.
	If there are an equal number of terms, and each term is double the original term,
	the two polys are equal.
*/
bool Poly::equals(const Poly &poly)
{
	//First check if terms are equal? Good idea? Would still need to simplify...
	//if(poly->pol.length() != 
	Poly *temp = addPoly(poly);
	temp = simplify(temp);
	
	list<term>::iterator it;
	
	
	
}