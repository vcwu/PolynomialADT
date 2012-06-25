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
#include <sstream>

using namespace std;

struct mappedPoly
{
	Poly p;
	string val[2];

	Poly* getTemplate() {return &p;}

};

void readInPolys(fstream &file, string fName, map<string, mappedPoly>* allPolys)
{
	int numPoly, coeff, exp1, exp2;
	string pName;
	
	if(file.is_open())
	{	
		
		file >> numPoly;
		while(numPoly > 0)
		{	
			file >> pName;
			bool more = true;
			(*allPolys)[pName] = mappedPoly();
			cout <<"name " << pName << endl;
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
					((*allPolys)[pName]).getTemplate()->addTerm(t);
				}
				
			}
			numPoly--;
			cout << *((*allPolys)[pName].getTemplate()) << endl;
			

		}
		
	}
}




int main()
{

	fstream file;
	file.open("test.txt");

	//Storing Polys to work with
	map<string, mappedPoly>* allPolys = new map<string, mappedPoly>;


	//Reading in polys from file
	cout << "Reading in polynomials from file..." << endl;
	readInPolys(file, "test.txt", allPolys);

	//Reading in and Executing commands
	//Code based on stackoverflow answer
	//http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c

	stringstream ss (stringstream::in || stringstream::out);
	string line;
	string command, key,val1, val2;
	enum {ADD, EQU, MUL };
	while(getline(file, line))
	{
		ss << line;
		//Strange. The first time I do this outside readInpolys, line is completely empty!
		//as if there were an empty line between commands and polys
		if(!line.empty())
		{
			//do something with line
			ss >> command;
			ss >> key >> val1, val2;
			

		}
	}

	
	//cout <<"Poly " << pName<<  * (*allPolys)[pName] << endl << endl;
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
	int c;
	cin >> c;


	return 0;
}