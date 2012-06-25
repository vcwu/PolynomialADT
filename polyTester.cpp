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
#include <ctype.h>

using namespace std;

struct mappedPoly
{
	Poly p;
	string val[2];

	mappedPoly() {}
	//makes a nice new copy of the pol template, can destroy it
	mappedPoly(Poly pol) { p = pol;}
	Poly* getTemplate() {return &p;}

	/*
	is_number from stack overflow answer
	modified to work for negative numbers as well

	goes through string char by char and compares using isdigit
	author: Charles Salvia 
	source:
	http://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
	*/
	static bool is_number(const std::string& s)
	{
		std::string::const_iterator it = s.begin();
		//added in test to check to check for '-'
		while (it != s.end() && (isdigit(*it)|| *it =='-' )) ++it;
		return !s.empty() && it == s.end();
	}
	/*
	Multiplies out constants, and forces
	the format of the Poly to follow <X,Y> to work with other methods

	if val is [x,y] no need to eval
	*/
	Poly* evaluate()
	{
		//Check if either val[0] or val[1] is a string
		

	}

};

void readInPolys(fstream &file, string fName, map<string, Poly>* allPolys)
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
			(*allPolys)[pName] = Poly();
			cout <<"name " << pName << " " << endl;
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
					((*allPolys)[pName]).addTerm(t);
				}
				
			}
			numPoly--;
			cout << ((*allPolys)[pName]) << endl << endl;
			
		}
	}
}




int main()
{

	fstream file;
	file.open("test.txt");

	//Storing Polys to work with
	map<string, Poly>* allPolys = new map<string, Poly>;


	//Reading in polys from file
	cout << "Reading in polynomials from file..." << endl;
	readInPolys(file, "test.txt", allPolys);

	//Reading in and Executing commands
	//Code based on stackoverflow answer
	//http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c

	stringstream ss (stringstream::in || stringstream::out);
	string line;
	string command, polKey; 
	string val1, val2;

	while(getline(file, line))
	{
		ss << line;
		//Strange. The first time I do this outside readInpolys, line is completely empty!
		//as if there were an empty line between commands and polys
		if(!line.empty())
		{
			//Mapping values to mappedPoly
			ss >> command;
			ss >> polKey >> val1 >> val2;

			mappedPoly* p1 = new mappedPoly((*allPolys)[polKey]);
			p1->val[0] = val1;
			p1->val[1] = val2;

			ss >> polKey >> val1, val2;
			mappedPoly* p2 = new mappedPoly((*allPolys)[polKey]);
			p2->val[0] = val1;
			p2->val[1] = val2;

			if(command == "add")
			{
				//p1->getTemplate()->addPoly(p1->p, p2->p);

			}
		}
	}

	
	string hello = "hello";
	cout << mappedPoly::is_number(hello);


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