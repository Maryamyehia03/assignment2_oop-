#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bigreal.h"
using namespace std;
int main()
{
    BigReal number1, number2,number3;
    string num1, num2;
    cout << "Enter the first number: \n";
    cin >> num1;
    cout << "Enter the second number: \n";
    cin >> num2;
    number1.setNum(num1); 
    number2.setNum(num2);
    if (!number1.isvalid())
    {
        cout << "Please, Enter the right number\n"; return 0;
    } 
    if (!number2.isvalid())
    {
        cout << "Please, Enter the right number\n"; return 0;
    } 
    number1.makebigreal(); number2.makebigreal();
   number3= number1.operator+(number2);
   number3.makebigreal();
   cout << number3.getbigreal() << " \n"<< number2.getbigreal() << " \n";
   
   //cout<< number1.getbigreal();
}
