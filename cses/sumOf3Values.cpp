#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, int>;
#define f first
#define s second

int main() {
    int N, X; cin >> N >> X;
    vector<pll> A(N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i].f);
        A[i].s = i+1;
    }
    sort(begin(A), end(A));
    for (int i = 0; i < N; ++i) {
        int j = i+1, k = N-1;
        while (j<N && k+1 && j < k) {
            int s = A[i].f + A[j].f + A[k].f;
            if (s < X) ++j;
            if (s > X) --k;
            if (s == X) {
                printf("%d %d %d\n", A[i].s, A[j].s, A[k].s);
                return 0;
            }
        }
    }
    printf("IMPOSSIBLE\n");

}
