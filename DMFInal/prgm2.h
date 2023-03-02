#include <iostream>
#include <vector>
#include <string>
#ifndef PRGM2_H
#define PRGM2_H
using namespace std;
class Class{
	public:
	Class(){
		classNum = "CSCI0";
		credits = 0;
		professor = "deez nutts";
		title = "Deez nuttsology";
		Days = "MWF";
		place = "MTV Cribs";
	}
	
	Class(string line){
		int pos =0;
		string delim = ",";
		string l = line;
		classNum = l.substr(pos,l.find(delim));
		l.erase(0,l.find(delim)+1);
		title = l.substr(pos,l.find(delim));
		for(int i=0;i<5;i++){
		l.erase(0,l.find(delim)+1);
		}
		professor = l.substr(pos+1 ,l.find(delim)-2);
		l.erase(0,l.find(delim)+1);
		Days = l.substr(pos,l.find(" "));
		l.erase(0,l.find(" ")+ 1);
		time = l.substr(pos,l.find(delim));
		l.erase(0,l.find(",") + 1);
		place = l.substr(pos,l.find(delim));
		pos = l.find(delim) + 1;
		string temp = l.substr(pos,l.find("\n"));
		credits = stoi(temp);
		}
	int findCreds(){
	return credits;
	}
	string getClassNum(){
	return classNum;}
	string printInfo(){
	string x = classNum + " " + title + " Taught by " + professor + " At " + Days + " "
	+time + " In " + place + "\n";
	return x;
	}
	private:
		string classNum;
		string professor;
		string title;
		string Days;
		string time;
		string place;
		int credits;
};

#endif 





