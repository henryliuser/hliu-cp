// https://atcoder.jp/contests/abc250/tasks/abc250_e
// actually pretty tough question.
// 2 pointers but be more logical and simplify the control flow
// if it feels too complicated, it is
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const int MXN = 2e5+5;

int N, Q;
int L[MXN], R[MXN];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    fill(L, L+MXN, MXN+1);
    fill(R, R+MXN, -1);

    cin >> N;
    set<int> a, b;
    vector<int> A(N), B(N);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;

    set<int> bq;
    int mn = -1;
    for (int i=0, j=0; i<N; ++i) {
        int p = A[i], q;
        if (a.count(p)) {
            L[i] = L[i-1];
            R[i] = R[i-1];
            continue;
        }
        // now, p is first encounter
        a.insert(p);
        bq.erase(p);
        while (j < N) {
            q = B[j++];
            if (!a.count(q))
                bq.insert(q);
            b.insert(q);
            if (q == p) {
                mn = j-1;
                break;
            }
        }
        while (j < N && b.count(B[j])) ++j;
        if (bq.empty() && b.count(p)) {
            L[i] = mn;
            R[i] = j-1;
        }
    }

    cin >> Q;
    for (int x,y, i=0; i < Q; ++i) {
        cin >> x >> y; --x, --y;
        if (L[x] <= y && y <= R[x]) cout << "Yes\n";
        else cout << "No\n";
    }

}
