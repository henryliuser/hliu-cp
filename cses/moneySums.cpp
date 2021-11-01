// O(N^2 log N) i think..
#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    set<int> sums;
    sums.insert(0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        vector<int> tmp;
        for (int y : sums)
            tmp.push_back(y + x);
        for (int y : tmp)
            sums.insert(y);
    }
    sums.erase(0);
    printf("%d\n", sums.size());
    for (int x : sums) printf("%d ", x);
    printf("\n");


}
