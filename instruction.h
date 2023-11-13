#pragma once
#include "registers.h"
#include "memory.h"
#include<string>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<stddef.h>
#include<cstdio>
#include "bitset"
#include "registers.h"
#include "memory.h"
using namespace std;
class instruction
{
private:
//conver int to hexa as a string
    string hex(int n){
        char hex_string[20];
        sprintf(hex_string, "%X", n); //convert number to hex
        return hex_string;
    }

public:
    registers registers00;
    memory memory;
    void instr(string s);
    int addTwoBinary(int num1, int num2);
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
};

