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

void Poly::addTerm(term t)
{	
	allTerms.push_back(t);
}

bool  Poly::isEmpty() const 
{
	return allTerms.empty();
}

ostream& operator<<(ostream& out, const Poly &p)
{
	list<term>::const_iterator it;
	string meat;
	
	if(!p.isEmpty())
	{
		for(it = p.allTerms.begin(); it != p.allTerms.end();)
		{
				//!Need params for mapping the different vars
				
				out << *it;

				//Hurrah! negative stays with coeff, prints perfectly
				it++;
				if(it != p.allTerms.end())
					out << " + ";
		}
	}
	else
	{
		out << "Polynomial has no terms." << endl;
	}
	return out;
}


/*
Simplify()
Non destructive, does NOT modify original polynomial

Note: If list has no terms, will return pointer to empty list

Used to combine like terms. 
1.  Sorts the polynomial in ascending terms,
then goes through and combines like terms. 

Constant inputs are taken care of already outside; 
they will have 0 0 exponents. 
*/

list<term>* Poly::simplify()
{
	//First, sort the polynomial, by firstExp then secondExp.
	//THe only time this will be a prob is when
	//we map have <x,y> and <y,x> mapped.

	list<term>*  p = this->getTerms();

	list<term>* tempList = new list<term>();

	if(!p->empty())	
	{
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
		
		int newCoeff = it->coeff;
		while(seek != p->end()) 
		{ 
			if(term::equalExponents(*it, *seek))
			{
				newCoeff += seek->coeff;
				//The problem occurs when I try and delete the LAST elem.
			}
			else
			{
				term t(newCoeff, it->getExp(1), it->getExp(2),it->val1, it->val2);
				it = seek;
				tempList->push_back(t);
				newCoeff = it->coeff;
			}
			seek++;	
		}
		//need to take care of the last group of like terms
		term t(newCoeff, it->getExp(1), it->getExp(2), it->val1, it->val2);
		tempList->push_back(t);
		
	}


	return tempList;
}


/*
	Precondition: Vars will always be x, then y in that order

	The two polynomials are sorted, then compared term by term.
*/
bool Poly::equals(Poly &poly1, Poly &poly2)
{
	//First simplify.
	/*
	list<term>* temp1;
	list<term>* temp2;

	temp1 = poly1.simplify(poly1.getTerms(),-1,-1);
	temp2 = poly2.simplify(poly2.getTerms(),-1,-1);
	*/
	list<term>* temp1 = poly1.simplify();
	list<term>* temp2 = poly2.simplify();

	//Comparing terms in each poly to each other. 
	while(!temp1->empty() && !temp2->empty())
	{
			if(temp1->front() == temp2->front())
			{
				temp1->pop_front();
				temp2->pop_front();
			}
			else
			{
				return false;
			}
	}
	return true;

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
addPoly
non destructive

Copies all terms in both polys into a single list,
then simplifies the whole thing. 
Returns a new poly. 
*/

Poly* Poly::addPoly(Poly &poly1, Poly &poly2)
{
	//Copy all terms into single list.
	list<term>* meat = new list<term>(poly1.getTerms()->begin(), 
		poly1.getTerms()->end());
	
	meat->insert(meat->end(),poly2.getTerms()->begin(), poly2.getTerms()->end());
	
	//This is really ugly. I should streamline it.
	Poly temp = Poly(meat);
	meat = temp.simplify();

	Poly* p = new Poly(meat);
	return p;

}

Poly& Poly::operator= (const Poly &rhs)
{
	if (this == &rhs)
		return *this;
	list<term> temp (rhs.allTerms.begin(), rhs.allTerms.end());

	allTerms = temp;


	return *this;
}
/*
Multiply
non Destructive

Multiplies by distribution.
First, distributes out the polies and adds new terms to a new list.
Simplifies the answer.
*/
Poly* Poly::multiply(Poly &poly1, Poly &poly2)
{
	//Distribute out the two polys. 
	list<term>* meat = new list<term>;

	list<term>* pol1 = poly1.getTerms();
	list<term>* pol2 = poly2.getTerms();

	list<term>::const_iterator point1 = pol1->begin();
	list<term>::const_iterator point2 = pol2->begin();

	while(point1 != pol1->end())
	{
		while(point2 != pol2->end())
		{
			//multiply point1 and point2 term
			//add result on meat list
			meat->push_back(term::multiply(*point1, *point2));
			point2++;
		}
		point2 = pol2->begin();
		point1++;
	}

	Poly* answer = new Poly(meat);
	return new Poly(answer->simplify());
}