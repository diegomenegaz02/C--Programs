#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class AddA;
class AddB;
class AddC;

//Diego Menegaz Lab 7



class Address {
// class members todo

	public:
		string delim= ".";
		Address(){
			for(int i=0;i<4;i++){
				nums.push_back(i);
			}
		}
		Address(string input){
			int start =0;
			if(input.length() > 0){
			string s;
			for(int i=0; i<4;i++){
				if(i==3){
					 s = input.substr(start,input.find("\n"));
				}else{
					 s = input.substr(start,input.find(delim));
				}
				start = input.find(delim) + 1;
				int n = stoi(s);
				nums.push_back(n);
			}}else{
			
			
			}}
		int firstOct(){
			return nums[0];
		}
		int numsIndex(int i){
			return nums[i];}
    		friend istream &operator>>(istream&, Address&);
    		friend ostream &operator<<(ostream&,const AddA&);
    		friend ostream &operator<<(ostream&,const AddB&);
    		friend ostream &operator<<(ostream&,const AddC&);

	private:
    		vector<int> nums;
};

class AddA{
	public:

		AddA(vector<Address> n){
			addresses.insert(addresses.begin(),n.begin(),n.end());
		}
		void AddAddress(Address a){
			addresses.push_back(a);}

		Address getBook(int index){
			return addresses[index];
		}
		void printaddress(){
			for(unsigned int i=0;i<addresses.size();i++){
				Address temp = getBook(i);
				string net = "Network: ";
				string host = "Host: ";
				string content = "";
				string dot =  ".";
				content = to_string(temp.numsIndex(0))+ dot + to_string(temp.numsIndex(1))+ dot + to_string(temp.numsIndex(2)); 
				cout << net << to_string(temp.numsIndex(0)) << host << content<<endl;
				content = "";
			}}
    		friend istream &operator>>(istream&, Address&);
    		friend ostream &operator<<(ostream&, const AddA&);
    		friend ostream &operator<<(ostream&, const AddB&);
    		friend ostream &operator<<(ostream&, const AddC&);
	private:
		vector<Address> addresses;
};
class AddB{
	public:
		AddB(vector<Address> n){
			addresses.insert(addresses.begin(),n.begin(),n.end());
		}
		void AddAddress(Address b){
			addresses.push_back(b);
		}


		Address getBook(int index){
			return addresses[index];
		}
		void printaddress(){
			for(unsigned int i=0;i<addresses.size();i++){
				Address temp = getBook(i);
				string net = "Network: ";
				string host = "Host: ";
				string dot = ".";
				string contentN ="";
				string contentH = "";
				contentH = to_string(temp.numsIndex(2))+ dot + to_string(temp.numsIndex(3)); 
				contentN = to_string(temp.numsIndex(0))+ dot + to_string(temp.numsIndex(1));
				cout << net  << contentN << host << contentH << endl;

			}}
    		friend istream &operator>>(istream&, Address&);
    		friend ostream &operator<<(ostream&, const AddA&);
    		friend ostream &operator<<(ostream&, const AddB&);
    		friend ostream &operator<<(ostream&, const AddC&);
	private:
		vector<Address>addresses;



};
class AddC{
	public:
		AddC(vector<Address> n){
			addresses.insert(addresses.begin(),n.begin(),n.end());
		}		
		void AddAddress(Address c){
			
			addresses.push_back(c);
		}
		Address getBook(int index){
			return addresses[index];
		}
		
		void printaddress(){
			for(unsigned int i=0;i<addresses.size();i++){
			Address temp = getBook(i);
			string net = "Network: ";
			string host = "Host: ";
			string dot = ".";
			string contentH = "";
			string contentN = "";
			contentH = temp.numsIndex(0);
			contentN = to_string(temp.numsIndex(1)) + dot + to_string(temp.numsIndex(2)) + dot + to_string(temp.numsIndex(3));
			cout << net  << contentN << host << contentH << endl;
		}}


    		friend istream &operator>>(istream&, Address&);
    		friend ostream &operator<<(ostream&, const AddA&);
    		friend ostream &operator<<(ostream&, const AddB&);
    		friend ostream &operator<<(ostream&, const AddC&);
	private: 
		vector<Address> addresses;


};



istream& operator>>(istream &input, Address &A) {
    // todo
    string temp;
    //create temp address to create constructor then replace empty constr data
    input >> temp;
    Address s(temp);
    A = s;
   
    
    return input;
}

ostream& operator<<(ostream &output, const AddA &A) {

return output;
}

ostream& operator<<(ostream &output, const AddB &B) {

return output;
}
ostream& operator<<(ostream &output, const AddC &C) {

    return output;
}

int main(void) {
    // create three vectors of type Address, one for each class
vector <Address> aList;
vector <Address> bList;
vector <Address> cList;
    // open the file
    ifstream instream;
    instream.open("/public/lab7/addresses.txt");
    int x;
int countC=0;
int countB=0;
int countA=0;
    Address a;
    while (instream >> a) {//constructor of a called in overload

	x = a.firstOct();//checks first num to see where placement should go
		if( x<128) {
			    aList.push_back(a);
			    countA++;
		}else if(x < 192){
			    bList.push_back(a);
			    countB++;
		} else if( x < 224){
			    cList.push_back(a);
			    countC++;
		}else{
	  		cout << "C or D Type Address" << endl; 
	
        // todoi
    }}
AddA AList(aList);
AddB BList(bList);
AddC CList(cList);//could not get overload to work stumped two TAs lol
cout <<"There are " << to_string(countA) <<" A Type Addresses" << endl;
AList.printaddress();
cout <<"There are " << to_string(countB) <<" B Type Addresses" << endl;
BList.printaddress();
cout <<"There are " << to_string(countC) <<" C Type Addresses" << endl;
CList.printaddress();
    instream.close();

    // print the content of the vectors using cout <<
    return(0);
}
