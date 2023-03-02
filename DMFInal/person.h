#include <iostream>
#include <vector>
#include <string>
#ifndef PERSON_H
#define PERSON_H
using namespace std;

class Person{
	public:
		Person(){
			firstName = "Deez";
			lastName = "Nutts";
			ID = 000000;
		}
		Person(string line){
		string l = line;
		string d = ",";
		int pos =0;
		lastName = l.substr(pos,l.find(d));
		l.erase(pos,l.find(d) + 1);
		firstName = l.substr(pos,l.find(d));
		l.erase(pos,l.find(d) + 1);
		ID = stoi(l.substr(pos,l.find(d)));
		
	}
		int  getID(){
			return ID;}
		int setID(int n){
			ID = n;
			return ID;
		}
		string getNameF(){
			return firstName;
		}
		string getNameL(){
			return lastName;
		}
		string fullName(){
			string temp = firstName + " " + lastName;
			return temp;
		}

	private:
		string firstName;
		string lastName;
		int ID;
};
#endif
