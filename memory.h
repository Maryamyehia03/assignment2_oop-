#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class memory
{
private:

    int cnt = 0;
    vector <pair<string, string>>vm={{"00","00"},{"01","00"}};

public:
    int print(string address);
    friend class instruction;
};

