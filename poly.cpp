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
#include <list>
using namespace std;

void Poly::addTerm(int coeff, int exp1, int exp2)
{	
	term t(coeff, exp1, exp2);
	allTerms.push_back(t);
}

ostream& operator<<(ostream& out, const Poly &p)
{
	list<term>::const_iterator it;
	string meat;
	
	//Need to figure out why my iterator isn't working.
	
	for(it = p.allTerms.begin(); it != p.allTerms.end();)
	{
		//!Need params for mapping the different vars
		if( !(it->getExp1() ==0 && it->getExp2() == 0))
		{
			out <<  it->getCoeff() 
				<< "x^" << it->getExp1() 
				<< "y^" << it->getExp2();
		}
		else
		{
			out << it->getCoeff();
		}
		//Hurrah! negative stays with coeff, prints perfectly
		it++;
		if(it != p.allTerms.end())
			out << " + ";
	}
	return out;
}


/*
Evaluate: 

A Poly is a template. Evaluate will evaluate the 
template poly, given two inputs; constant integer inputs
will be multiplied out and simplifed, while the exponents with 
variable inputs will be forced to the format <x,y>. 
An entirely new Poly will be made. If
*/

Poly* Poly::evaluate(const Poly &pol)
{





	Poly* meat = new Poly();
	return meat;
}


/*
Sorts the polynomial in place, in 
ascending order by "X" then "Y".
Nothing is simplifed.  
*/


/*
Simplify()
Destructive

Used to combine like terms. 
1.  Sorts the polynomial in ascending terms,
then goes through and combines like terms. 

Constant inputs are taken care of already outside; 
they will have 0 0 exponents. 
*/

list<term>* Poly::simplify(list<term>*  p, int xPosition, int yPosition)
{
	//First, sort the polynomial, by firstExp then secondExp.
	//THe only time this will be a prob is when
	//we map have <x,y> and <y,x> mapped.
	if(p != 0)	
		p->sort();

	//Combine like terms. 
	//it keeps track of the first term of a 
	//group of like terms, while
	//seek moves forward and destroys like terms.
	list<term>::iterator it = p->begin();
	list<term>::iterator seek = it;
	seek++;

	//No need to combine only one term
	

	/*ISSUE
	Logic error.
	COmpletely skips over the last term in the list. 
	Because now if it is the bound, seek will go off the far end.
	*/
	list<term>* tempList = new list<term>();
	int newCoeff = it->coeff;
	while(seek != p->end()) 
	{ 
			if(*it == *seek)
			{
				newCoeff += seek->coeff;
				//The problem occurs when I try and delete the LAST elem.
			}
			else
			{
				term t(newCoeff, it->getExp1(), it->getExp2());
				it = seek;
				tempList->push_back(t);
				newCoeff = it->coeff;
			}
			seek++;
	}
	//need to take care of the last group of like terms
	term t(newCoeff, it->getExp1(), it->getExp2());
	tempList->push_back(t);
	return tempList;
}


/*
	Precondition: Vars will always be x, then y in that order

	The two polynomials are sorted, then 
	merged together. 
*/
bool Poly::equals(const Poly &poly)
{
	//First simplify and combine like terms...
	//if(poly->pol.length() != 
	//Poly *temp = addPoly(poly);
	//temp = simplify(temp);
	
	list<term>::iterator it;
	

	//Comparing number of terms. 

	//Comparing terms in each poly to each other. 


	return true;
	
}