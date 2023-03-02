#include <iostream>
#include <vector>
#include <string>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;


class Employee : private Person{
	public:
		//works or at least runs through will check later
		Employee(){
		creditsAble = 7;
		}
		Employee(string line){
			string temp = line;
			int pos =0;
			string delim = ",";
			string f = "FT";
			string p = "PT";
			for(int i=0;i<3;i++){
				temp.erase(0,temp.find(delim) +1);
			}	
			string x = temp.substr(0,temp.find(","));
			if(f.compare(x)==0){
					creditsAble = 7;
					FT = true;
		}	else 	{
			creditsAble = 3;
			FT = false;
		}
		}
		int  getCreds(){
			return creditsAble;
		}
		
		
	private:
		bool FT;
		int creditsAble;
};

#endif 

