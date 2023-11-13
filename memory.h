#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
//#include "registers.h"
//#include "instruction.h"
#include <string>
#include <sstream>
using namespace std;
class memory
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
    int cnt = 0;
    vector<pair<string, string>> v;
public:
   memory();
    void storev(string value);
    string printhexa(string address);
     int printint(string address);
    void read();
void loadm(string add,string val);
    friend class instruction;

};

