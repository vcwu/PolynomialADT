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
	Poly pol2;
	Poly* pointer1 = & pol1;

	pol1.addTerm(1,1,1);
	pol1.addTerm(1,1,1);
	pol1.addTerm(3,2,3);
	pol1.addTerm(3,2,3);
	pol1.addTerm(3,9,3);
	pol1.addTerm(3,9,3);

	pol2.addTerm(1,1,1);
	pol2.addTerm(1,1,1);
	pol2.addTerm(3,2,3);
	pol2.addTerm(3,2,3);
	pol2.addTerm(3,9,3);
	pol2.addTerm(3,9,3);


	cout << "Pol1: " << pol1 << endl;
	cout << "Pol2 " << pol2 << endl;
	
	//Testing equality
	if(pol1.equals(pol1, pol2))
		cout << "Pol1 and Pol 2 are equal!" << endl;
	else
		cout <<"Nope. not equal. " << endl;




	//Testing simplification
	list<term>* meat = pol1.simplify(pol1.getTerms(), 9,9);
	cout << "Simplified??" <<  *meat;

	cin >> c;
	return 0;
}