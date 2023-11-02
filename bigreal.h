#pragma once
#include<string>
using namespace std;
class BigReal
{
private:
    
    char sign;
    string s1, s2, num;
public:
	
	//BigReal(const BigReal& other); // Copy constructor
	//BigReal& operator= (BigReal& other); // Assignment operator
	//// Depending on how you store data, default can be enough
	void setNum(string realNumber);

	BigReal operator+ (BigReal other);
	//BigReal operator- (BigReal& other);
	//bool operator< (BigReal anotherReal);
	//bool operator> (BigReal anotherReal);
	//bool operator== (BigReal anotherReal);
	//friend ostream& operator << (ostream& out, BigReal num);
	BigReal(char si,string st1,string st2);
	BigReal();
	bool isvalid();
    string getbigreal();
	void makebigreal();
	
};

