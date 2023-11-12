#include "instruction.h"
//#include "registers.h"
//#include "memory.h"
#include "bitset"
#include<iostream>

using namespace std;

int instruction::addTwoBinary(int num1, int num2)
{
    // Convert integers to binary strings
    std::bitset<32> binary1(num1);
    std::bitset<32> binary2(num2);

    // Perform binary addition
    std::bitset<32> sum = binary1.to_ulong() + binary2.to_ulong();

    // Check for overflow
    if (sum[31] != sum[30]) {
        std::cerr << "Overflow occurred!" << std::endl;
        // Handle overflow as needed
    }

    // Return the result as an integer
    return static_cast<int>(sum.to_ulong());
}


void instruction::instr(string s)
{


    // while (s != "c000")
    //  {
    if (s[0] == '1')
    {
        registers00.load1r(s[1], memory.print(conv2(s[2], s[3])));
        cout << registers00.read(s[1]) << "\n";
    }
    else if (s[0] == '2')
    { cout<<s[1]<<" "<<s[2]<<" "<<s[3]<<"\n";
        registers00.load1r(s[1], con1(conv2(s[2], s[3])));
        cout << registers00.read(s[1]) << "\n";
    }
    else if (s[0]=='3')
    {

    }
    else if (s[0] == '4' && s[1]=='0')
    {
       registers00.load1r(s[3],registers00.read(s[2]));
        cout<<registers00.read(s[3])<<"\n";
    }
    else if (s[0]=='5')
    {
        registers00.load1r(s[1], addTwoBinary(registers00.read(s[2]), registers00.read(s[3])));
        cout << registers00.read(s[1]) << "\n";
    }
    else if (s[0]=='B')
    {

    }

     //}
}



