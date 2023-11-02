#pragma once
#include<string>
using namespace std;
class BigReal
{
private:
    
    char sign;
    string s1, s2, num;
public:
	//friend ostream& operator << (ostream& out, BigReal num);
	//BigReal operator+ (BigReal other);
	//BigReal operator- (BigReal& other);
	//BigReal(const BigReal& other); // Copy constructor
	//BigReal& operator= (BigReal& other); // Assignment operator
	//// Depending on how you store data, default can be enough
	void setNum(string realNumber);
	bool operator< (BigReal anotherReal);
	bool operator> (BigReal anotherReal);
	bool operator== (BigReal anotherReal);
	BigReal(char si,string st1,string st2);
	BigReal();
	bool isvalid();
    string getbigreal();
	void makebigreal();
	
};

