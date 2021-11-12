#include <bits/stdc++.h>
using namespace std;

vector<int> factorize(int n)
{
    int i;
    vector<int> factors;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0)
            factors.push_back(i);
    }
    if (i - (n / i) == 1) --i;
    for (; i >= 1; i--) {
        if (n % i == 0)
            factors.push_back(n/i);
    }
    return factors;
}

int main() {
    for (int f : factorize(60))
        printf("%d ", f);
}
