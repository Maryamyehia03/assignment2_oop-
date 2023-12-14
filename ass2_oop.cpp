#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bigreal.h"
using namespace std;
int main()
{ 
    string num1, num2;
    cout << "Enter the first number: \n";
    cin >> num1;
    cout << "Enter the second number: \n";
    cin >> num2;


    BigReal number1, number2;
    number1.setNum(num1);number2.setNum(num2);
    if (!number1.isvalid())
    {
        cout << "Please, Enter the right number\n"; return 0;
    }
    if (!number2.isvalid())
    {
        cout << "Please, Enter the right number\n"; return 0;
    }

    number1.makebigreal(); number2.makebigreal();

    int x;
    cout << "Choose\n1. +\n2. -\n3. >\n4. <\n5.==\n0. Exit\n ";
    cin >> x;
    if (x==1)
    {
      BigReal number3= number1+number2;
      cout << number3.getbigreal() << " \n";

    }

    else if (x==2)
    {
        BigReal number3 = number1 - number2;
        cout << number3.getbigreal() << " \n";

    }

    else if (x==3)
    {
        if (number1 > number2) cout << "YES, The first number is greater than the second number\n";
        else cout<<"NO, The first number isn't greater than the second number\n ";
    }

    else if (x==4)
    {
        if (number1 < number2) cout << "YES, The first number is smaller than the second number\n";
        else cout << "NO, The first number isn't smaller than the second number\n";
    }

    else if (x==5)
    {
        if (number1 == number2)cout << "YES, The first number is equal to the second number\n";
        else cout << "NO, The first number isn't equal to the second number\n";
    }

}
