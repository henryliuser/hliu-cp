#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct yuh {
    int x;
    yuh(int x): x(x) {}
};

int main() {
    yuh a(1);
    yuh b(2);
    yuh* p = &a;
    string a1 = "abcdefg";
    string b1 = a1.substr(0,2);
    string c1 = a1.substr(1,3);
    yuh idc(1235);
}
