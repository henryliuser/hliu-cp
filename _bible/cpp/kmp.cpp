#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> kmp(string &s) {
    int N = s.size();
    vector<int> pi(N);
    for (int i = 1; i < N; ++i) {
        int j = pi[i-1];
        while (j && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

// return 1st position of t in s or -1 if not in s
int find(string &s, string &t) {
    if (t == "") return 0;
    int N = t.size();
    string a = t + "@" + s;
    auto pi = kmp(a);

    int K = a.size();
    for (int i = N+1; i < K; ++i) {
        if (pi[i] == N)
            return i - 2*N;
    }
    return -1;
}
