/*
CS 352, Summer '12
Victoria Wu

Polynomial ADT Tester
-----------------------------------------

*/

#include <iostream>
#include "poly.h"

int main()
{

	Poly pol1;

	Poly* point = & pol1;
	/*
	int coeff, tempExp, tempExp2;
	cin >> coeff ;
	cin >> tempExp;
	cin >> tempExp2;
	
	cout << "Coeff: " << coeff <<endl << "Exp: " << tempExp << endl
		<< "Exp2: " << tempExp2 << endl;
	*/

	pol1.addTerm(coeff, tempExp, tempExp2);
	pol1.addTerm(-5,7,3);
	cout << "ThePOL: " << pol1 << endl;



	cin >> coeff;
	return 0;
}