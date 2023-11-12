#include "memory.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include "registers.h"
using namespace std;

int memory::print(string addres)
{
    if (cnt > 255)
    {
        cout << "Sorry! The memory is full\n"; return 0;
    }
    cnt++;
    for (auto it : vm) {
        if (it.first == addres)
        {
            string s = it.second;
            int ans;
            sscanf(s.c_str(), "%x", &ans);
            return(ans);

        }
    }
    cout << "The address isn't found\n";
    return 0;
}
