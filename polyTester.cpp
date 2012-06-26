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
	
	mappedPoly(Poly pol) 
	{
		p.setTerms(pol.getTerms());
	}


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

void EatFile(fstream &file, string fName, map<string, Poly>* allPolys)
{
	int numPoly, coeff, exp1, exp2;
	string pName;
	
	fstream out;
	out.open("Output_Accuracy.txt");

	if(file.is_open())
	{	
		//Read in all the stuff. 
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
			out << pName <<": " << ((*allPolys)[pName]) << endl << endl;
			
		}
	
		//Parse the commands. 
		//Strange. Will continue to go one more time, though there's nothing
		//else in the file..
		while(!file.eof())
		{
			string command, polKey1, polKey2; 
			string val1, val2;

			file >> command;

			file>> polKey1 >> val1 >> val2;
			mappedPoly* p1 = new mappedPoly((*allPolys)[polKey1]);
			p1->val[0] = val1;
			p1->val[1]  =val2;
			out << "Mapped: " << val1 << " " <<val2 << endl;

			file>> polKey2 >> val1 >> val2;
			mappedPoly* p2 = new mappedPoly((*allPolys)[polKey2]);
			p2->val[0] = val1;
			p2->val[1] = val2;
			out << "Mapped: " << val1 << " " <<val2 << endl;


			p1->evaluate();
			p2->evaluate();
			out << command << " " << polKey1  <<" "<<polKey2<< endl;

			if(command == "add")
			{
				
				Poly* meat = p1->getPoly()->addPoly(p1->p, p2->p);
				out << "Adding " << polKey1 << " and " << polKey2 << endl;
				out << "Answer: " << *meat << endl << endl;
			}

			else if(command == "equ")
			{
				bool ans = p1->getPoly()->Poly::equals(p1->p, p2->p);
				out << "Equality? " << polKey1 << " and " << polKey2 << endl;
				if(ans)
				out << "Answer: True" << endl << endl;
				else
					out << "Answer: False" << endl << endl;
			}
			else if(command == "mul")
			{
				Poly* meat = p1->getPoly()->multiply(p1->p, p2->p);
				out << "Multiply " << polKey1 << " and " << polKey2 << endl;
				out << "Answer: " << *meat << endl << endl;
			}
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
	EatFile(file, "test.txt", allPolys);
	file.close();
	
	/*
	//TESTING ADDITION
	fstream file2;
	file2.open("Output_TestingAddition.txt");

	//Making a very large polynomial.
	for(int x = 1000; x < 16000; x += x)
	{
		Poly* pol1 = new Poly();
		Poly* pol2 = new Poly();
		for(int i = 0; i < x; i++)
		{	
			//This ensures that no terms are like, and nothing
			//will simplify. 
			term t1(i+1, i+2, i+3);
			term t2(i+2, i+1, i+1);
			pol1->addTerm(t1);
			pol2->addTerm(t2);
		}

		file2 << "Pol 1 terms: " << pol1->getTerms()->size() <<endl;
		file2 << "Pol 2 terms: " << pol2->getTerms()->size() <<endl;

		file2 << "Num of Operations: " 
		 << pol1->addPolyTest(*pol1, *pol2) << endl << endl;
	}
	file2.close();
	*/

	/*
	TESTING SIMPLIFY
	fstream file2;
	file2.open("Output_TestingSimplify.txt");

	for(int x = 1000; x <= 32000; x += x)
	{
		Poly* pol1 = new Poly();
		Poly* pol2 = new Poly();
		for(int i = 0; i < x; i++)
		{	
			//This ensures that all terms are alike.
			term t1(i+1, 2,2);
			term t2(i+2, 2,2);
			pol1->addTerm(t1);
			pol2->addTerm(t2);
		}

		file2 << "Pol 1 terms: " << pol1->getTerms()->size() <<endl;
		file2 << "Pol 2 terms: " << pol2->getTerms()->size() <<endl;

		file2 << "Num of Operations: " 
		 << pol1->simplifyTester() << endl << endl;
	}
	*/

	/*
	//TESTING EQUALITY
	fstream file2;
	file2.open("Output_TestingEquality.txt");

	//Making a very large polynomial.
	for(int x = 1000; x < 16000; x += x)
	{
		Poly* pol1 = new Poly();
		Poly* pol2 = new Poly();
		for(int i = 0; i < x; i++)
		{	
			//This ensures that no terms are alike,
			//but both polynomials are equal.
			term t1(i+1, 2,2+i);
			term t2(i+2, 2,2+i);
			pol1->addTerm(t1);
			pol2->addTerm(t2);
		}

		file2 << "Pol 1 terms: " << pol1->getTerms()->size() <<endl;
		file2 << "Pol 2 terms: " << pol2->getTerms()->size() <<endl;

		file2 << "Num of Operations: " 
		 << pol1->equalsTester(*pol1, *pol2) << endl << endl;
	}
	file2.close();
	*/

	/*
	//TESTING MULTIPLICATION
	fstream file2;
	file2.open("Output_TestingMultiplication.txt");

	//Making a very large polynomial.
	for(int x = 100; x < 800; x += x)
	{
		Poly* pol1 = new Poly();
		Poly* pol2 = new Poly();
		for(int i = 0; i < x; i++)
		{	
			//This ensures that no terms are like, and nothing
			//will simplify. 
			term t1(i+1, i+2, i+3);
			term t2(i+2, i+1, i+1);
			pol1->addTerm(t1);
			pol2->addTerm(t2);
		}

		file2 << "Pol 1 terms: " << pol1->getTerms()->size() <<endl;
		file2 << "Pol 2 terms: " << pol2->getTerms()->size() <<endl;

		file2 << "Num of Operations: " 
		 << pol1->multiplyTester(*pol1, *pol2) << endl << endl;
	}
	file2.close();
	*/
	
	int c;
	cin >> c;
	return 0;
}