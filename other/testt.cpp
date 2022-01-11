#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s = "01234";
    for (int i = 0; i < s.size()-1; ++i)
        cout << s.substr(i, i+2) << '\n';

}
