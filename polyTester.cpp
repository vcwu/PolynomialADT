/*
CS 352, Summer '12
Victoria Wu

Polynomial ADT Tester
-----------------------------------------

*/

#include <iostream>
#include <list>
#include "poly.h"
#include <fstream>
#include <string>
#include <map>

using namespace std;
int main()
{
	//Storing Polys to work with
	map<string, Poly*> allPolys;

	//Reading in polys from file
	fstream file;
	file.open("test.txt");
	int numPoly, coeff, exp1, exp2;
	string pName;
	
	if(file.is_open())
	{	
		file >> numPoly;
		while(numPoly > 0)
		{	
			file >> pName;
			cout << pName;
			bool more = true;
			allPolys[pName] = new Poly();
			
			while(more)
			{
				file >> coeff >> exp1 >>exp2 ; 
				term t (coeff, exp1, exp2);
				if(!(coeff||exp1||exp2))
				{
					more = false;
				}
				else
				{
					allPolys[pName]->addTerm(t);
				}
			}

			cout <<"Poly " << pName<<  * allPolys[pName] << endl << endl;
			numPoly--;
		}
	}
	file.close();


	int c;

	/*
	cout << "Pol1: " << pol1 << endl;
	cout << "Pol2 " << pol2 << endl;
	
	//Testing equality
	if(pol1.equals(pol1, pol2))
		cout << "Pol1 and Pol 2 are equal!" << endl;
	else
		cout <<"Nope. not equal. " << endl;

	//Testing simplification, 
	//doesn't change original!
	list<term>* meat = pol1.simplify();
	cout << "Simplified?? " <<  Poly(meat) <<endl;

	//Testing Adding
	Poly* polAdded = pol1.addPoly(pol1,pol2);
	cout << endl << "Adding... " << endl;
	cout << pol1 << " added to " << pol2 << endl;
	cout << "SOLUTION" <<  *polAdded << endl;

	//testing Multiplication
	Poly* mult = pol1.multiply(pol1, pol2);
	cout << endl << "Multiply... " << endl;
	cout << pol1 << " times " << pol2 << endl;
	cout << "SOLUTION" <<  *mult << endl;



	cout << "Original pol1: " << pol1 << endl;
	cout << "Original pol2: " << pol2 << endl;
	*/
	cin >> c;


	return 0;
}