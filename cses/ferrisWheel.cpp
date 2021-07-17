#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5;
int w[maxN]; // weights
int main() {

    int ans = 0;
    int N, X; scanf("%d%d", &N, &X);
    for (int z = 0; z < N; ++z)
        scanf("%d", &w[z]);
    sort(w, w+N);

    int i = 0, j = N-1;
    while (i < j) {
        int a = w[i];
        int b = w[j];
        while (i < j && a + b > X) b = w[--j], ++ans;
        if (i < j) ++i, --j, ++ans;
    }
    printf("%d\n", ans + (i==j));



}
