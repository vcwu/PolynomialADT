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
	
	pol1.addTerm(-5,7,3);
	pol1.addTerm(2,7,3);
	pol1.addTerm(1,7,3);
	pol1.addTerm(3,1,2);
	pol1.addTerm(4,3,7);
	cout << "ThePOL: " << pol1 << endl;

	//pol1.simplify(pol1->pol);

	
	list<term> *haha = NULL;
	pol1.sortPoly(haha,3,3);


	cin >> c;
	return 0;
}