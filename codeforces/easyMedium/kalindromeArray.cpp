// https://codeforces.com/problemset/problem/1610/B

/* Instructive problem.
First, reduce:
1. palindromes on the ends are fine
2. you only need to check 2 - either first or last
3. if you check a deletion, you can delete ALL occurrences
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int> A;

bool check(int i, int j, int del) {
    while (i < j) {
        while (i < j && A[i] == del) ++i;
        while (i < j && A[j] == del) --j;
        if (A[i] != A[j]) return false;
        ++i; --j;
    }
    return true;
}

string solve() {
    cin >> N; A.resize(N);
    for (int &x: A) cin >> x;

    int i = 0, j = N-1;
    while (i < j && A[i] == A[j]) ++i, --j;
    if (i == j) return "YES";
    if (check(i, j, A[i])) return "YES";
    if (check(i, j, A[j])) return "YES";
    return "NO";
}

int main() {
    int T; cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }
}
