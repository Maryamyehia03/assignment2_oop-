#pragma once
#include <vector>
#include<string>
#include <bits/stdc++.h>
using namespace std;
class registers
{
private:
    int size = 0;
    vector<pair<char, int>>v{ {'0',0},{'1',0},{'2',0},{'3',0},{'4',0},{'5',0},{'6',0},{'7',0},{'8',0},{'9',0},{'A',0},{'B',0},{'C',0},{'D',0},{'E',0},{'F',0} };
public:
  //  registers();
    int read(char reg);

    void load1r(char regist, int value);

    bool check(char reg);

    friend class instruction;

};


