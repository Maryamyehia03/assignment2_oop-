#include "memory.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

memory::memory() {
    for (int i = 0; i < 256; i++) {
        if (i<16){
            v.push_back({conv2('0',hex(i)[0]),"00"});
            continue;
        }
        v.push_back({hex(i),"00"});
    }
}

void memory::storev(string value) {
    v[cnt].second=conv2(value[0],value[1]);
    cnt++;

    v[cnt].second= conv2(value[2],value[3]);
    cnt++;

}

int memory::printint(string address) {

    for (auto it:v) {
        if (it.first==address){
            int ans;
             sscanf(it.second.c_str(), "%x", &ans);
             sscanf(it.second.c_str(), "%X", &ans);
            return ans;
        }
    }
    cout<<"The address isn't found\n";
    return 0;
}

string memory::printhexa(string address) {
    for (auto it:v) {
        if (it.first==address){
            return it.second;
        }
    }
    cout<< "The address isn't found\n";
}

void memory::read() {
    for (int i = 0; i < 256; i++) {
       cout<< v[i].first<<" "<<v[i].second<<"\n";
    }
}

void memory::loadm(string add, string val) {
    for (auto &it:v) {
        if (it.first==add){
            it.second=val;
            return;
        }
    }
}











