#pragma once
#include<string>
using namespace std;
class BigReal
{
private:

	bool temp = false;
    char sign;
    string s1, s2, num;
public:
    void samesize(string& s1,string& anothers1){
        int size = (s1.size() - anothers1.size());
        if (s1.size()>anothers1.size()){
            for (int i = 0; i < size; ++i) {
                anothers1="0"+anothers1;
            }
        }
        else if (s1.size()<anothers1.size()){ size = (anothers1.size() - s1.size());
            for (int i = 0; i < size; ++i) {
                s1="0"+s1;
            }
        }
    }

    void same2(string& s2,string& anothers2){
        int size = (s2.size() - anothers2.size());
        if (s2.size()>anothers2.size()){
            for (int i = 0; i < size; ++i) {
                anothers2.push_back('0');
            }
        }
        else if (s2.size()<anothers2.size()){ size = (anothers2.size() - s2.size());
            for (int i = 0; i < size; ++i) {
                s2.push_back('0');
            }
        }
    }

    void delet(string& s1){
        int n=0;
        for (int i = 0; i <s1.size(); ++i) {
            if (s1[i]=='0')s1.erase(s1.begin()+i),i=-1;
            else break;
        }
    }

    void delet2(string& s2){
        for (int i = s2.size()-1; i >=0; --i) {
            if (s2[i]=='0')s2.pop_back();
            else break;
        }
    }
    //BigReal;

    BigReal();

	//// Depending on how you store data, default can be enough
	void setNum(string realNumber);

	BigReal operator- (BigReal anotherReal);

	bool operator< (BigReal anotherReal);

	bool operator> (BigReal anotherReal);

	bool operator== (BigReal anotherReal);

	BigReal(char si,string st1,string st2);

	bool isvalid();

    string getbigreal();

	void makebigreal();

    BigReal  operator+(BigReal anotherReal) ;


};
