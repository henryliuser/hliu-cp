#include <bits/stdc++.h>
using namespace std;

set<int> primeFactors(int x) {
    set<int> s;
    for (int i = 2; i < sqrt(x); ++i) {
        if (x % i == 0) {
            auto s = primeFactors(x/i);
            s.insert(i);
            return s;
        }
    }
    s.insert(x);
    return s;
}

vector<int> primeFactors(int x, vector<int>& spf) {
    vector<int> factors;  // or unordered_set
    while (x != 1) {
        factors.push_back(spf[x]);  // or insert()
        x /= spf[x];
    }
    return factors;
}
