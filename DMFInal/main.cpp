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


vector<Class> readinLineC();
vector<Employee> readinLineE();
vector<Student> readinLineS();
vector<Person> readinLineP(string file);










int main(void){
	vector<Student> students= readinLineS();
	vector<Employee> employees= readinLineE();
	vector<Class> classes = readinLineC();
	vector<Person> peopleE = readinLineP("/public/pgm2/employees.csv");//Both Person and student/prof will be same spot in arr; 
	vector<Person> peopleS = readinLineP("/public/pgm2/students.csv");// PersonS[0] = Students[0]
	string name;
	string line;
	vector<string> Cnames;
	int credSLeft = 0;
	cout <<"Enter Name Here " << endl;	
	getline(cin,name);
	
	
	int iter= 0;
	bool es = false;
	for(unsigned int k =0; k<peopleS.size();k++){
		int r = name.compare(peopleS[k].fullName());
		if(r ==0){	
		iter = k;
		es = true;
		}
	}
	for(unsigned int j=0;j<peopleE.size();j++){	
		int x = name.compare(peopleE[j].fullName());	
		 if(x ==0){
			iter = j;
			es = false;
			break;}
	}

	if(es == true){
	cout << peopleS[iter].fullName() << " ID: " << peopleS[iter].getID() << " Current Credits " << students[iter].findCredits() << endl;
	}else{
		
	cout << peopleE[iter].fullName() << " ID: " << peopleE[iter].getID() << " Current Credits "<< employees[iter].getCreds() << endl;;
	}


	int r = name.compare("n");
	if(r == 0){
		return 0;
	}
	cout<< "What Classes would you like to enter?" << endl;
	getline(cin, line);
	string temp = line;
	while(temp.length()>1){
		string x = temp.substr(0,temp.find(" "));
		Cnames.push_back(x);
		temp.erase(0,temp.find(" ") +1);
	}
	vector<Class> canTake;
	vector<Class> cantTake;
	cout << es << endl;
	if(es == true){
	credSLeft = students[iter].findCredits();
	}else if(es == false){
		credSLeft = employees[iter].getCreds();	
	}
	for(unsigned int i=0;i<Cnames.size();i++){
		for(unsigned int j =0;j < classes.size();j++){
			int d = Cnames[i].compare(classes[j].getClassNum());
			
			if(d ==0 && credSLeft> classes[j].findCreds()){
				credSLeft = credSLeft - classes[j].findCreds();
				canTake.push_back(classes[j]);
			}else if(d==0){
				cantTake.push_back(classes[j]);
			}
		}}
	cout << "Is Registered for" << endl;
	for(unsigned int e=0;e<canTake.size();e++){
	string t = canTake[e].printInfo();
	cout << t << endl;
	}
	for(unsigned int z;z<cantTake.size();z++){
		cout << "Cannot Register For: " << cantTake[z].getClassNum() << endl;
	}


return 0;
	}
	
	
	
	



