#pragma once
#include <vector>
#include<string>
#include <bits/stdc++.h>
using namespace std;
class registers
{
private:
    //conver int to hexa as a string
    string hex(int n){
        char hex_string[20];
        sprintf(hex_string, "%X", n); //convert number to hex
        return hex_string;
    }
    //convert hexa as a string to int
    int con1(string hexa) {
        int ans;
        sscanf(hexa.c_str(), "%x", &ans);
        return ans;
    }
    //collect two char to one string
    string conv2(char c1, char c2) {
        string coll;
        coll.push_back(c1);
        coll.push_back(c2);
        return coll;
    }
    int size = 0;
    vector<pair<char, int>>vr{ {'0',0},{'1',255},{'2',0},{'3',0},{'4',0},{'5',0},{'6',0},{'7',0},{'8',0},{'9',0},{'A',0},{'B',0},{'C',0},{'D',0},{'E',0},{'F',0} };
public:
  //  registers();
    int read(char reg);

    void load1r(char regist, int value);

    bool check(char reg);

    void print();
    friend class instruction;

};


