#include "memory.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int memory::print(string address)
{
    if (cnt > 255)
    {
        cout << "Sorry! The memory is full\n"; return 0;
    }
    cnt++;
    for (auto it : vm) {
        if (it.first == address)
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
