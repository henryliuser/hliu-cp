#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool same(deque<int> &a, deque<int> &b) {
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) return false;
    return true;
}

bool check(deque<int> &r, deque<int> &A) {
    deque<int> res;
    int i = 0, j = r.size() - 1;
    while (i < j) {
        if (r[i] < r[j]) res.push_front(r[i++]);
        else res.push_back(r[j--]);
    }
    res.push_back(r[i]);
    if (same(res, A)) return true;
    res.pop_back();
    res.push_front(r[i]);
    if (same(res, A)) return true;
    return false;
}

deque<int> solve(deque<int> &A) {
    deque<int> res;
    int i = 0, j = A.size()-1;
    while (i < j) {
        if (A[i] < A[j]) res.push_front(A[i++]);
        else res.push_back(A[j--]);
    }
    res.push_back(A[i]);
    bool c1 = check(res, A);
    if (c1) return res;
    res.pop_back();
    res.push_front(A[i]);
    bool c2 = check(res, A);
    if (c2) return res;
    return {-1};
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        deque<int> A(N);
        for (int &x : A) cin >> x;
        auto s = solve(A);
        for (int x : s) cout << x << " ";
        cout << "\n";
    }
}
