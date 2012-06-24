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

ostream& operator<<(ostream& out, const Poly &p)
{
	list<term>::const_iterator it;
	string meat;
	
	//Need to figure out why my iterator isn't working.
	
	for(it = p.pol.begin(); it != p.pol.end(); ++it)
	{
		out <<  it->getCoeff();
	}
	

	return out;
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
	//Poly *temp = addPoly(poly);
	//temp = simplify(temp);
	
	list<term>::iterator it;
	
	return true;
	
}