#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int x, vector<int>& spf) {
    vector<int> factors;  // or unordered_set
    while (x != 1) {
        factors.push_back(spf[x]);  // or insert()
        x /= spf[x];
    }
    return factors;
}
