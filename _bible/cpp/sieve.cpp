#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int N) {
    vector<int> spf(N+1);  // smallest prime factor
    spf[0] = spf[1] = -1;
    for (int i = 3; i <= N; i += 2) spf[i] = i;
    for (int i = 2; i <= N; i += 2) spf[i] = 2;  // avoid lots of % later
    for (int i = 3; i*i <= N; i += 2) {
        if (spf[i] != i) continue;
        for (int j = i*i; j <= N; j += i)
            if (spf[j] == j)
                spf[j] = i;
    }
    return spf;
}

// runs in 1.7 ish seconds on 1e7
vector<ll> sumDiv(int N) {
    vector<ll> s(N+1);
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; j += i)
            s[j] += i;
    return s;
}

vector<bool> sieveBool(int N) {
    vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= N; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i*i; j <= N; j += i)
            is_prime[j] = false;
    }
    return is_prime;
}

int main() {
    int N = 10000;
    vector<int>  spf      = sieve(N);
    vector<bool> is_prime = sieveBool(N);
    for (int z = 0; z <= N; ++z)
        if (is_prime[z] && spf[z] != z)
            cout << "WRONG: " << z << endl;

    for (int z = 0; z <= N; ++z) {
        if (spf[z] == z)
            cout << z << endl;
    }
}
