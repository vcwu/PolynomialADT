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

#include <list>
#include <utility>
using namespace std;

struct term
{

	pair < int, pair < int, int > > t;	
	
	term() { t.first = 0; t.second.first = 0; t.second.second = 0;}
	term(int coeff, int exp1, int exp2)  
	{
		t.first = coeff; 
		t.second.first = exp1; 
		t.second.second = exp2;
	}
	
	int getCoeff()	{return t.first; }
	
	//Do I really need this??
	pair<int, int> getExponents(){return t.second; }
	
};
	
class Poly
{

	private:
		
		list<term> pol;	
		
		Poly* simplify(Poly* pol);
		
	public:
		Poly() {}
		void addTerm(int coeff, int exp1, int exp2);
		friend ostream& operator<<(ostream& out, const Poly &poly);
		//ack need to account for the mapping of <x,y> v < y,x>
		bool equals(const Poly &pol);
		Poly* addPoly(const Poly &pol);
		Poly* multiply(const Poly &pol);
				
		
};




