#include "bigreal.h"
#include <algorithm>
#include<cmath>
#include <iostream>
using namespace std;

//BigReal BigReal::operator+(BigReal other)
//{
//   
//    string st1, st2;
//    if (sign == other.sign) {
//       st1 =to_string (stoi(s1) + stoi(other.s1));
//       st2 =to_string (stoi(s2) + stoi(other.s2));
//       return BigReal(sign, st1, st2);
//    }
//   /* else {
//
//    }*/
//  
//}

void BigReal::setNum(string realNumber)
{
    num = realNumber;
}

bool BigReal::operator<(BigReal anotherReal)
{
    if (sign == anotherReal.sign)
    {
        if (sign == '+' && anotherReal.sign == '+')
        {
            if (s1.size() > anotherReal.s1.size()) {
                return false;
            }
            else if (s1.size() < anotherReal.s1.size()) {
                return true;
            }
            else if (s1.size() == anotherReal.s1.size()) {
                for (int j = 0; j < (s1.size(), anotherReal.s1.size()); j++)
                {
                    if (s1[j] > anotherReal.s1[j]) {
                        return false;
                    }
                    else if (s1[j] < anotherReal.s1[j]) {
                        return true;
                    }
                }
            }
            else {
                for (int j = 1; j < max(s2.size(), anotherReal.s2.size()); j++)
                {
                    if (s2[j] > anotherReal.s2[j]) {
                        return false;
                    }
                    else if (s2[j] < anotherReal.s2[j]) {
                        return true;
                    }
                }
            }
        }
        else  if (sign == '-' && anotherReal.sign == '-') {
            if (s1.size() < anotherReal.s1.size()) {
                return false;
            }
            else if (s1.size() > anotherReal.s1.size()) {
                return true;
            }
            else if (s1.size() == anotherReal.s1.size()) {
                for (int j = 0; j < (s1.size(), anotherReal.s1.size()); j++)
                {
                    if (s1[j] < anotherReal.s1[j]) {
                        return false;
                    }
                    else if (s1[j] > anotherReal.s1[j]) {
                        return true;
                    }
                }
            }
            else {
                for (int j = 1; j < max(s2.size(), anotherReal.s2.size()); j++)
                {
                    if (s2[j] < anotherReal.s2[j]) {
                        return false;
                    }
                    else if (s2[j] > anotherReal.s2[j]) {
                        return true;
                    }
                }
            }
        }
    }
    else if (sign == '+' && anotherReal.sign == '-')return false;
    else return true;

}

bool BigReal::operator>(BigReal anotherReal)
{
    if (sign == anotherReal.sign)
    {
        if (sign == '+' && anotherReal.sign == '+')
        {
            if (s1.size() > anotherReal.s1.size()) {
                return true;
            }
            else if (s1.size() < anotherReal.s1.size()) {
                return false;
            }
            else if (s1.size() == anotherReal.s1.size()) {
                for (int j = 0; j < (s1.size(), anotherReal.s1.size()); j++)
                {
                    if (s1[j] > anotherReal.s1[j]) {
                        return true;
                    }
                    else if (s1[j] < anotherReal.s1[j]) {
                        return false;
                    }
                }
            }
            else {
                for (int j = 1; j < max(s2.size(), anotherReal.s2.size()); j++)
                {
                    if (s2[j] > anotherReal.s2[j]) {
                        return true;
                    }
                    else if (s2[j] < anotherReal.s2[j]) {
                        return false;
                    }
                }
            }
        }
        else if (sign = '-' && anotherReal.sign == '-') {
            if (s1.size() < anotherReal.s1.size()) {
                return true;
            }
            else if (s1.size() > anotherReal.s1.size()) {
                return false;
            }
            else if (s1.size() == anotherReal.s1.size()) {
                for (int j = 0; j < (s1.size(), anotherReal.s1.size()); j++)
                {
                    if (s1[j] < anotherReal.s1[j]) {
                        return true;
                    }
                    else if (s1[j] > anotherReal.s1[j]) {
                        return false;
                    }
                }
            }
            else {
                for (int j = 1; j < max(s2.size(), anotherReal.s2.size()); j++)
                {
                    if (s2[j] < anotherReal.s2[j]) {
                        return true;
                    }
                    else if (s2[j] > anotherReal.s2[j]) {
                        return false;
                    }
                }
            }
        }
    }
    else if (sign == '+' && anotherReal.sign == '-') return true;
    else if (sign = '-' && anotherReal.sign == '+')return false;
}

bool BigReal::operator==(BigReal anotherReal)
{
    if (sign != anotherReal.sign)
    {
        return false;
    }
    if (s1.size()!=anotherReal.s1.size())
    {
        return false;
    }
    else {
        for (int j = 0; j <s1.size(); j++)
        {
            if (s1[j] > anotherReal.s1[j]) {
                return false;
            }
            else if (s1[j] < anotherReal.s1[j]) {
                return false;
            }
        }
    }
     if (s2.size()!=anotherReal.s2.size())
    {
        return false;
    }
     else {
         for (int j = 1; j < s2.size(); j++)
         {
             if (s2[j] > anotherReal.s2[j]) {
                 return false;
             }
             else if (s2[j] < anotherReal.s2[j]) {
                 return false;
             }
         }
     }
     if (sign == anotherReal.sign)
     {
         return true;
     }
    
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


BigReal::BigReal(double realNumber) {
    s1=0.0;
    s2=0.0;
    num=0.0;

}

BigReal::BigReal(string realNumber) {
    num=realNumber;

}




