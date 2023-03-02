#include <iostream>
#include <vector>
#include <string>
#ifndef STUDENT__H
#define STUDENT__H
using namespace std;

class Student{
	public:
		//When going through line use copy as line is fucky af
		Student(){
			creditsAble = 21;

		}
		Student(string line){
			int pos=0;
			string temp = line;
			string delim = ",";
			for(int i =0;i<4;i++){
				pos = temp.find(delim) +1;
				temp.erase(0,pos);
			}
			string x = temp.substr(0,line.find("\n"));
			creditsAble = stoi(x);
		}
		int findCredits(){
			return creditsAble;
		}

	private:
		int creditsAble;
};
#endif
