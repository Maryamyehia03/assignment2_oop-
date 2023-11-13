#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "registers.h"
#include "memory.h"
#include "instruction.h"
#include <vector>
#include <iostream>
#include<fstream>
using namespace std;
int main() {

string s,name;
instruction instruction;
cout<<"Please enter your file name: \n";
cin>>name;
    fstream file(name+".txt");
    if (!file.is_open()){cout<<"Please enter the right name file\n";return 0;}

    while (file) {
        getline(file,s);

        if (s=="C000")break;
        instruction.instr(s);
    }
    instruction.memory.storev("C000");
    cout<<"memory is :\n";
instruction.memory.read();

 cout<<"Register is :\n";
instruction.registers00.print();

    file.close();

    return 0;
}
