#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "registers.h"
#include "instruction.h"
using namespace std;
class memory 
{
private:

	int cnt = 0;
	vector <pair<string, string>>vm;

public:
	
	int print(string addres);
};

