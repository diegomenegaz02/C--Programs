#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "prgm2.h"
#include "student.h"
#include "person.h"
#include "employee.h"
using namespace std;
//Diego Menegaz Main Program 2 11/24/2022 Thanksgiving can wait


vector<Class> readinLineC( ){
	vector<Class> Vec;
	string line;
	ifstream inFile;
	inFile.open("/public/pgm2/classes.csv");
	while(getline(inFile,line)){
	string x = line;
	Class temp(x);
	Vec.push_back(temp);
	}
	return Vec;
	}


vector<Student> readinLineS( ){
	vector<Student> Vec;
	string line;
	ifstream inFile;
	inFile.open("/public/pgm2/students.csv");
	while(getline(inFile,line)){
	string x = line;
	Student temp(x);
	Vec.push_back(temp);
	}
	return Vec;	
	}

vector<Person> readinLineP(string file){
	vector<Person> Vec;
	string line;
	ifstream inFile;
	inFile.open(file);
	while(getline(inFile,line)){
		string x =line;
		Person temp(x);
		Vec.push_back(temp);
	}
	return Vec;
}

vector<Employee> readinLineE( ){
	vector<Employee> Vec;
	string line;
	ifstream inFile;
	inFile.open("/public/pgm2/employees.csv");
	while(getline(inFile,line)){
		string x = line;
		Employee temp(x);
		Vec.push_back(temp);
	}
	return Vec;
	}


