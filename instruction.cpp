#include "instruction.h"
#include "registers.h"
#include "memory.h"
#include<iostream>
using namespace std;

void instruction::instr(string s)
{
    
        // while (s != "c000")
       //  {
        if (s[0] == '1')
        {
            registers.load1r(s[1], memory.print(conv2(s[2], s[3])));
            cout << registers.read(s[1]) << "\n";
        }
        else if (s[0] == '2')
        {
            registers.load1r(s[1], con1(conv2(s[2], s[3])));
            cout << registers.read(s[1]) << "\n";
        }
    
       // }
}
