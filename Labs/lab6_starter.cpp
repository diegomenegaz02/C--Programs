#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Writen by DIego MEnegaZ
class Term {
    private:
    int coeff;
    int exp;
    public:
    Term(string);
    Term() {coeff = 0; exp = 0; };
    void print();
    int get_exp() { return exp; }
    void set_exp(int e) { exp = e; }
    int get_coeff() { return coeff; }
    void set_coeff(int n) { coeff = n; }
};

void Term::print() {
	int e = this->get_exp();
	int c = this->get_coeff();
if(e!=-1 && c!= 0){

	if(e == 0){
		cout << c<< " + ";
	}else{
		cout << c << "x" << e << " + ";
    // todo print shit
}}}

Term::Term(string input) {		
	string subCoe;
	string subExp;
	string delim = "x";
	if(input.length() == 1){//will only have length of 1 with no x or exp
		subCoe = input;
		this->set_coeff(stoi(subCoe));
		this->set_exp(0);
	}else if(input.length() == 2){//will only have 2 spots no coeff but will have x
		if(input.find(delim) == 0){ //if x is in first pos coe =1, and exp will be in input[1]
		      this->set_coeff(1);
		      input.erase(0,1);
		      this->set_exp(stoi(input));
		}else if(input.find(delim) == 1){//if x in in the second spot exp = 1, and coe will be in input[0]
			this->set_exp(1);
			input.erase(1);	// erases after first char
			this->set_coeff(stoi(input));
		}
	}else{ //Full term
	subCoe = input.substr(0,input.find(delim));//Coe will be in input[0]
	int g = stoi(subCoe);//make int 
	this->set_coeff(g);//set coeff	
	input.erase(0,input.find(delim)+1); //Erases the coe and x leaving the exponent we know exists
	subExp = input;
	int x = stoi(subExp);//make int
	this->set_exp(x); //Set exp
	}
}

class Polynomial {
    private:
    vector<Term> terms;
    public:
    void simplify();
    void read();
};

void Polynomial::read() {
	string str;
	char  op;
	bool done = false;
    while (!done) {
        cin >> str; // one term
        cin >> op;  // +
	Term temp(str);
	terms.push_back(temp);
        if (cin.eof()) {
            done = true;
        }

        // todo
        // use str to create a Term
        // add it to the terms vector
    }
}

bool compare(Term t1, Term t2) {
    return t1.get_exp() > t2.get_exp();
}

void Polynomial::simplify() {
    sort(terms.begin(), terms.end(), compare);

   
    for(auto i = terms.begin();i!=terms.end();i++){
cout <<  "Before:" << i->get_coeff()<< "x"  << i->get_exp() << endl;}








    for(auto i=terms.begin();i!=terms.end()-1;i++){				
	for(int j = 1;j<terms.size();j++){
		
		if(i->get_exp() == terms[j].get_exp()){
			int g = i->get_coeff() +terms[j].get_coeff();

			i->set_coeff(g);
			cout << i->get_coeff() << g<< endl;
			terms.erase(terms.begin()+j );
			
	}
	}
   }
    for(auto i = terms.begin();i!=terms.end();i++){
	    cout << "After: " <<  i->get_coeff()<< "x" << i->get_exp() << endl;
    }
}

int main(void) {
    // you don't need to add anything else to main

    Polynomial poly;
    poly.read();
    poly.simplify();
    return(0);
}
