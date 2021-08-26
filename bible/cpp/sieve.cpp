#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 10000;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int z = 0; z < n+1; ++z)
        if (is_prime[z])
            cout << z << " ";
}
