/*
CS 352, Summer '12
Victoria Wu

Polynomial ADT Tester
-----------------------------------------

*/

#include <iostream>
#include <list>
#include "poly.h"

int main()
{
	int c;

	Poly pol1;

	Poly* pointer1 = & pol1;
	/*
	int coeff, tempExp, tempExp2;
	cin >> coeff ;
	cin >> tempExp;
	cin >> tempExp2;
	
	cout << "Coeff: " << coeff <<endl << "Exp: " << tempExp << endl
		<< "Exp2: " << tempExp2 << endl;
	*/

	//pol1.addTerm(coeff, tempExp, tempExp2);
	


	

	cout << "ThePOL: " << pol1 << endl;


	list<term>* meat = pol1.simplify(pol1.getTerms(), 9,9);

	cout << "Simplified??" <<  *meat;

	cin >> c;
	return 0;
}