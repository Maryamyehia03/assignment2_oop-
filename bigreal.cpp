#include "bigreal.h"
#include <algorithm>
#include<cmath>
#include <iostream>
using namespace std;

void BigReal::setNum(string realNumber)
{
    num = realNumber;
}



BigReal BigReal::operator+(BigReal other)
{
   
    string st1, st2;
    if (sign == other.sign) {
       st1 =to_string (stoi(s1) + stoi(other.s1));
       st2 =to_string (stoi(s2) + stoi(other.s2));
       return BigReal(sign, st1, st2);
    }
   /* else {

    }*/
  
}

bool BigReal::isvalid()
{
    int i; bool temp = true;
    if (num[0] == '+' || num[0] == '-')
    {
        if (num.size() == 1) { return false; }
        i = 1;
    }
    else
    {
        i = 0;
    }
    for (; i < num.size(); ++i) {
        if (num[i] == '.') {
            temp = false;
            i++;
            break;
        }

        else if ((num[i] < '0' || num[i]>'9') && num[i] != '.') { return false; }
    }
    if (!temp) {
        for (; i < num.size(); ++i) {
            if (num[i] == '.') { return false; }
        }
    }
    return true;
}

string BigReal::getbigreal()
{
    return sign+s1+s2;
}

void BigReal::makebigreal()
{
    int i; bool temp = true;
    if (num[0] == '+' || num[0] == '-')
    {
        sign = num[0];
        i = 1;
    }
    else
    {
        sign = '+';
        i = 0;
    }
    for (; i < num.size(); ++i) {
        if (num[i] == '.') {
            temp = false;
            s2.push_back(num[i]);
            i++;
            break;
        }
      
        else {
            s1.push_back(num[i]);
        }

    }
    if (!temp) {
        for (; i < num.size(); ++i) {
            s2.push_back(num[i]);
        }
    }
}





