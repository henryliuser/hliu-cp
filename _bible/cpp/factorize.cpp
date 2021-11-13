#include <bits/stdc++.h>
using namespace std;

set<int> factorize(int n) {
    set<int> f;
    for (int x = 1; x*x <= n; ++x)
        if (n % x == 0) {
            f.insert(n / x);
            f.insert(x);
        }
    return f;
}

vector<int> factorize(int n)
{
    int i;
    vector<int> factors;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0)
            f.push_back(i);
    }
    if (i - (n / i) == 1) --i;
    for (; i >= 1; i--) {
        if (n % i == 0)
            f.push_back(n/i);
    }
    return f;
}
