#include "bigreal.h"
#include <algorithm>
#include<cmath>
#include <iostream>
using namespace std;

BigReal BigReal::operator+(BigReal other)
{
    int cary = 0;
    long long result1 = 0, res1, result11 = 0;
    long long  res2 = 0, result22 = 0, result2 = 0;
    long long min2, min22, min0;
    char ci;
    if (sign == other.sign) {
        temp = true;
        //collect part integer
        ci = sign;
        for (char digit : s1) {
            result1 = result1 * 10 + (digit - '0');
        }
        for (char digit : other.s1) {
            result11 = result11 * 10 + (digit - '0');
        }
        res1 = result1 + result11;
        //-------------------------------------------
        //pad small string from the right by 0
        if (s2.size() > other.s2.size()) {
            for (int j = 0; j < (s2.size() - other.s2.size()); ++j) {
                other.s2.push_back('0');
            }
        }
        else if (s2.size() < other.s2.size()) {
            for (int j = 0; j < (other.s2.size() - s2.size()); ++j) {
                s2.push_back('0');
            }
        }
        //-------------------------------------------------------------
        //collect part fraction
        for (char digit : s2) {
            result2 = result2 * 10 + (digit - '0');
        }
        for (char digit : other.s2) {
            result22 = result22 * 10 + (digit - '0');
        }
        res2 = result2 + result22;
        cary = res2;
        //----------------------------------
        //take the carry
        while (true) {
            if (cary == 1 || cary == 0)break;
            cary = cary / 10;
        }
        return BigReal(ci, res1 + cary, res2);
    }
    //**********************************************
    if (sign != other.sign && sign == '+') {

        //  return BigReal(sign,s1,s2)-other;
    }
    else if (sign != other.sign && sign == '-') {
        //  return other-BigReal(sign,s1,s2);
    }
}

void BigReal::setNum(string realNumber)
{
    num = realNumber;
}

string result1, result2;

BigReal BigReal::operator-(BigReal other) {

 
    if (sign == '+' && other.sign == '-') {
        return BigReal(sign,s1,s2) + other;
    }
    else if (sign == '-' && other.sign == '+') {
        return  other - BigReal(sign, s1, s2);

    }
    BigReal number1(), number3();


    if (s1.size() < other.s1.size()) {
        int difference = other.s1.size() - s1.size();
        for (int j = 0; j < difference; j++) {
            s1.insert(j, "0");
        }

    }
    if (s1.size() > other.s1.size()) {
        int difference = s1.size() - other.s1.size();
        for (int j = 0; j < difference; j++) {
            other.s1.insert(j, "0");
        }

    }
    if (s2.size() > other.s2.size()) {
        int difference = s2.size() - other.s2.size();
        for (int j = 0; j < difference; j++) {
            other.s2.insert(j, "0");
        }

    }
    if (s2.size() < other.s2.size()) {
        int difference = other.s2.size() - s2.size();
        for (int j = 0; j < difference; j++) {
            s2.insert(j, "0");
        }

    }
    if (other.sign == '+' && sign == '+') {
        int carry = 0, digit, digitother, subtract;
        string result1;
        for (int j = other.s2.size(); j >= 1; j--) {
            digit = s2[j] - '0';
            digitother = other.s2[j] - '0';
            subtract = digit - digitother - carry;
            if (subtract < 0) {
                subtract += 10;
                carry = 1;
            }
            else if (subtract >= 0) {
                carry = 0;
                result1.push_back(subtract);
            }


        }
        string result2 = "";
        for (int j = other.s1.size(); j >= 0; j--) {
            digit = s2[j] - '0';
            digitother = other.s2[j] - '0';
            subtract = digit - digitother - carry;
            if (subtract < 0) {
                subtract += 10;
                carry = 1;
            }
            else if (subtract >= 0) {
                carry = 0;
                result2.push_back(subtract);
            }



        }




        number3().s1 = result2;
        number3().s2 = result1;


        return number3();

    }
    else if (sign == '-' && other.sign == '-') {
        int carry = 0, digit, digitother, subtract;
        string result1;
        for (int j = other.s2.size(); j >= 1; j--) {
            digit = s2[j] - '0';
            digitother = other.s2[j] - '0';
            subtract = digitother - digit - carry;
            if (subtract < 0) {
                subtract += 10;
                carry = 1;
            }
            else if (subtract >= 0) {
                carry = 0;
                result1.push_back(subtract);
            }
        }

        for (int j = other.s1.size(); j >= 0; j--) {
            digit = s2[j] - '0';
            digitother = other.s2[j] - '0';
            subtract = digitother - digit - carry;
            if (subtract < 0) {
                subtract += 10;
                carry = 1;
            }
            else if (subtract >= 0) {
                carry = 0;
                result2.push_back(subtract);
            }
        }

    }


    number3().s1 = result2;
    number3().s2 = result1;

   

    return number3();
   


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

BigReal::BigReal(char cc, long long n1, long long n2)
{
    sign = cc;
    s1 = to_string(n1);
    s2 = to_string(n2);
    if (temp == true) s2.erase(s2.begin());
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
    return sign + s1 + s2;
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
    s1 = 0.0;
    s2 = 0.0;
    num = 0.0;

}

BigReal::BigReal(string realNumber) {
    num = realNumber;

}

BigReal BigReal::operator=(BigReal other)
{
    sign = other.sign;
    s1 = other.s1;
    s2 = other.s2;
    return BigReal(sign, s1, s2);
}

