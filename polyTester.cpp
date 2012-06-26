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
#include <math.h>

using namespace std;

struct mappedPoly
{
	Poly p;
	string val[2];

	mappedPoly() {}
	~mappedPoly() { }
	//makes a nice new copy of the pol template, can destroy it
	mappedPoly(Poly pol) {  p = pol;}
	Poly* getPoly() {return &p;}

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
	void evaluate()
	{
		//Check if either val[0] or val[1] is a string
		list<term>* terms = p.getTerms();
		list<term>::iterator it = terms->begin();
		while(it != terms->end())
		{
			//Will check for swapped positions, since
			//use of simplify requires forcing to <x,y>. 
			if(val[0] == "y" || val[1] == "x")
				it->swap();

			for(int index = 0; index < 2; index ++)
			{
				//Distributing out the number. 
				if(is_number(val[index]))
				{
					//no logical loss of precision, since exponents 
					//and vars will always be ints
					int eval = pow((double)atoi(val[index].c_str()), it->exp[index]);
					it->coeff = (it->coeff) * eval;

					//Resetting exponent to zero, since it has been replaced by num
					it->exp[index] = 0;
				}
			}
			++it;
		}
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
			p1->val[1]  =val2;

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

	*/


	
	mappedPoly* p1 = new mappedPoly((*allPolys)["p1"]);
	p1->val[0] = "x";
	p1->val[1] = "y";

	mappedPoly* p4 = new mappedPoly((*allPolys)["p4"]);
	p4->val[0] = "x";
	p4->val[1] = "y";
	
	mappedPoly* p2 = new mappedPoly((*allPolys)["p2"]);
	p2->val[0] = "y";
	p2->val[1] = "x";
	
	p4->evaluate();
	p1->evaluate();
	p2->evaluate();
	
	cout << "Original pol1: " << (*allPolys)["p1"] << endl;
	cout << "Modifiesd Poly " << p1->p << endl;

	cout << "Original pol4: " << (*allPolys)["p4"] << endl;
	cout << "Modifiesd pol4 " << p4->p << endl;
	
	cout << "Original pol2: " << (*allPolys)["p2"] << endl;
	cout << "Modifiesd pol2 " << p2->p << endl;

	list<term>* tester = p2->p.simplify();
	
	//Addding def doesn't work T.T
	Poly pop1 = p1->p;
	Poly pop2 = p2->p;
	Poly* meat = pop1.addPoly(pop1, pop2);
	cout << *meat << endl;

	cout << "Original pol2: " <<  (*allPolys)["p2"]<< endl;
	
	int c;
	cin >> c;


	return 0;
}