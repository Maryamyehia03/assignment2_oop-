#include "bigreal.h"
#include <algorithm>
#include<cmath>
#include <iostream>
using namespace std;

void BigReal::setNum(string realNumber)
{
    num = realNumber;
}

bool BigReal::operator<(BigReal anotherReal)
{
    if (sign == anotherReal.sign)
    {
        if (sign == '+' && anotherReal.sign == '+') {
            if (s1.size() > anotherReal.s1.size()) {
                return false;
            }

            else if (s1.size() < anotherReal.s1.size()) {
                return true;
            }

            else if (s1.size() == anotherReal.s1.size()) {
                for (int j = 0; j < (s1.size()); j++) {
                    if (s1[j] > anotherReal.s1[j]) {
                        return false;
                    }
                    else if (s1[j] < anotherReal.s1[j]) {
                        return true;
                    }
                }
                {
                    for (int j = 0; j <  anotherReal.s2.size(); j++) {
                        if (s2[j] > anotherReal.s2[j]) {
                            return false;
                        }
                        else if (s2[j] < anotherReal.s2[j]) {
                            return true;
                        }
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
                for (int j = 0; j < (s1.size()); j++) {
                    if (s1[j] < anotherReal.s1[j]) {
                        return false;
                    } else if (s1[j] > anotherReal.s1[j]) {
                        return true;
                    }
                }
                {
                    for (int j = 0; j < s2.size(); j++) {
                        if (s2[j] < anotherReal.s2[j]) {
                            return false;
                        } else if (s2[j] > anotherReal.s2[j]) {
                            return true;
                        }
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
                for (int j = 0; j < (s1.size()); j++) {
                    if (s1[j] > anotherReal.s1[j]) {
                        return true;
                    } else if (s1[j] < anotherReal.s1[j]) {
                        return false;
                    }
                }
                {
                    for (int j = 0; j <  anotherReal.s2.size(); j++) {
                        if (s2[j] > anotherReal.s2[j]) {
                            return true;
                        } else if (s2[j] < anotherReal.s2[j]) {
                            return false;
                        }
                    }
                }
            }
        }
        else if (sign = '-' && anotherReal.sign == '-') {
            if (s1.size() < anotherReal.s1.size()) {
                return true;
            } else if (s1.size() > anotherReal.s1.size()) {
                return false;
            } else if (s1.size() == anotherReal.s1.size()) {
                for (int j = 0; j < (s1.size(), anotherReal.s1.size()); j++) {
                    if (s1[j] < anotherReal.s1[j]) {
                        return true;
                    } else if (s1[j] > anotherReal.s1[j]) {
                        return false;
                    }
                }
                for (int j = 0; j < s2.size(); j++) {
                    if (s2[j] < anotherReal.s2[j]) {
                        return true;
                    } else if (s2[j] > anotherReal.s2[j]) {
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
    if (s1.size() != anotherReal.s1.size())
    {
        return false;
    }
    else {
        for (int j = 0; j < s1.size(); j++)
        {
            if (s1[j] > anotherReal.s1[j]) {
                return false;
            }
            else if (s1[j] < anotherReal.s1[j]) {
                return false;
            }
        }
    }
    if (s2.size() != anotherReal.s2.size())
    {
        return false;
    }
    else {
        for (int j = 0; j < s2.size(); j++)
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
        if (num.size() <= 1) { return false; }
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
            else if ((num[i] < '0' || num[i]>'9') ) { return false; }
        }
    }
    return true;
}

string BigReal::getbigreal()
{
    delet(s1);
    delet2(s2);
    return sign + s1 +'.'+ s2;
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
            //s2.push_back(num[i]);
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
    }else s2="0";
}

BigReal::BigReal(char si, string st1, string st2) {
sign=si;
s1=st1;
s2=st2;
}

BigReal::BigReal() {
sign='+';
s1="";
s2="";
}

BigReal BigReal::operator-(BigReal anotherReal) {

    if (anotherReal.sign == '+') anotherReal.sign = '-';
    else if (anotherReal.sign == '-') anotherReal.sign = '+';

    return (BigReal(sign,s1,s2)+anotherReal);
}

BigReal BigReal::operator+(BigReal anotherReal) {
    samesize(s1,anotherReal.s1);
    same2(s2,anotherReal.s2);

    BigReal res, cup;
    bool bigger = false;

    if (sign == anotherReal.sign) {
        int carry = 0; char temp;

        res.sign = sign;
        //fraction (+,+)|(-,-)
        for (int i = s2.size()- 1; i >= 0; i--) {
            temp = carry + s2[i] + anotherReal.s2[i] - '0';
            carry = 0;
            if (temp > '9') {
                carry = 1;
                temp -= 10;
            }
            res.s2 = temp + res.s2;
        }
        //------------------------------------------------------------
        //integer (+,+)|(-,-)
        for (int i = s1.size() - 1; i >= 0; i--) {
            temp = carry + s1[i] + anotherReal.s1[i] - '0';
            carry = 0;
            if (temp > '9') {
                carry = 1;
                temp -= 10;
            }
            res.s1 = temp + res.s1;
        }
        if (carry == 1) {
            res.s1 = "1" + res.s1;
        }

    }
        //-----------------------------------------------------------------------------------
     else {
        //take bigger number
        res.sign = sign;
        if (s1 > anotherReal.s1) {
            bigger = true;
        }
        else if (s1 == anotherReal.s1) {
            if (s2 > anotherReal.s2) {
                bigger = true;
            }
            else res.sign=anotherReal.sign;
        }
        else  res.sign=anotherReal.sign;

       // make bigger number in s1
        if (bigger == false) {
            cup.s1 = s1; cup.s2 = s2;
            s1 = anotherReal.s1; s2 = anotherReal.s2;
            anotherReal.s1 = cup.s1; anotherReal.s2 = cup.s2;
            res.sign = anotherReal.sign;
        }

        //----------------------------------------------------------------------------
        //fraction (+,-)
        int temp, borrow = 0;
        for (int i = s2.size()-1; i>=0; --i) {
            if (s1==""&&i==0){
                temp = abs(s2[i] - anotherReal.s2[i] - borrow);
                borrow=0;

            }
            else {
                temp = s2[i] - anotherReal.s2[i] - borrow;
                if (temp < 0) {
                    temp += 10;
                    borrow = 1;
                } else
                    borrow = 0;
            }

            res.s2 = char(temp + '0')+res.s2 ;
        }
        //----------------------------------------------------------
        //integer part (+,-)
        for (int i = s1.size() - 1; i >= 0; --i) {
            if (i==0){
                temp = abs(s1[i] - anotherReal.s1[i] - borrow);
                borrow=0;
            }
            else {
                temp = s1[i] - anotherReal.s1[i] - borrow;
                if (temp < 0) {
                    temp += 10;
                    borrow = 1;
                } else
                    borrow = 0;
            }
            res.s1 = char(temp + '0') + res.s1;
        }
    }
    return  res;
}
