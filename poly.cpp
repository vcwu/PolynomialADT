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
	pol.push_back(t);
}

ostream& operator<<(ostream& out, const Poly &p)
{
	list<term>::const_iterator it;
	string meat;
	
	//Need to figure out why my iterator isn't working.
	
	for(it = p.pol.begin(); it != p.pol.end();)
	{
		//!Need params for mapping the different vars
		out <<  it->getCoeff() 
			<< "x^" << it->getExp1() 
			<< "y^" << it->getExp2();

		//Hurrah! negative stays with coeff, prints perfectly
		it++;
		if(it != p.pol.end())
			out << " + ";
	}
	return out;
}

/*
Sorts the polynomial in place, in 
ascending order by "X" then "Y".
Nothing is simplifed.  
*/

void sortPoly()
{ 
	//

	//First sort by X input. 


}

/*
Simplify()

Used to combine like terms. 
First sorts the polynomial in ascending terms,
then goes through and combines like terms. 
*/

Poly* Poly::simplify(list<term>*  p)
{
	Poly* meat = new Poly();
	





	return meat;
}


/*
	Precondition: Vars will always be x, then y

	The two polynomials are sorted, then 
	merged together. 
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