#include "registers.h"
#include <iostream>
using namespace std;

bool registers::check(char reg) {
    if (size > 15)
    {
        return false;
    }
    else {
        for (auto it : v)
        {
            if (it.first == reg)return true;
        }
    }
    return false;
}

int  registers::read(char reg)
{
    if (!check(reg))return 0;
    for (auto it : v)
    {
        if (it.first == reg)
        {
            return it.second;
        }
    }
    return 0;
}

void registers::load1r(char regist, int value)
{
    if (size > 15)
    {
        cout << "Sorry! The register is full\n"; return;
    }
    size++;
    for (auto& it : v) {
        if (it.first == regist)
        {
            it.second = value;
            return;
        }
    }
    cout << "Sorry! The register isn't found\n";
    return;
}
