// https://cses.fi/problemset/task/2217
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N+1), B(N+2);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        B[ A[i] ] = i;
    }
    B.back() = 1e9;  // dummy val
    int cur = 1;
    for (int x = 1; x <= N; ++x)
        cur += (B[x] < B[x-1]);

    for (int i,j, q=0; q < M; ++q) {
        cin >> i >> j;
        if (A[i] > A[j]) swap(i, j);
        int a = A[i], b = A[j];

        for (int x : {a, b})
            cur -= (B[x] < B[x-1]),
            cur -= (B[x+1] < B[x]);
        if (b-a == 1)
            cur += (B[b] < B[a]);  // avoid double count

        swap(B[a], B[b]);
        swap(A[i], A[j]);
        for (int x : { a,b })
            cur += (B[x] < B[x-1]),
            cur += (B[x+1] < B[x]);
        if (b-a == 1)
            cur -= (B[b] < B[a]);  // avoid double count
        cout << cur << '\n';
    }


}
