#pragma once
#include "registers.h"
#include "memory.h"
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
class instruction 
{
private :
	registers registers;
	memory memory;
protected:
	//convert hexa as a string to int
	int con1(string hexa) {
		int ans;
		sscanf(hexa.c_str(), "%x", &ans);
		return ans;
	}
	//collect two char to one string 
	string conv2(char c1, char c2) {
		string coll;
		coll.push_back(c1 + c2);
		return coll;
	}
public:

	void instr(string s);

};

