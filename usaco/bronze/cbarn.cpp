#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <math.h>
#include <limits.h>

using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int N; cin >> N;
    vector<int> cows(N);
    int total = 0;
    for (int z = 0; z < N; z++) {
        cin >> cows[z];
        total += cows[z];
    }

    int ans = INT_MAX;
    for (int z = 0; z < N; z++) {
        int curr = total;
        int walked = 0;
        for (int a = z; a < z+N; a++) {
            curr -= cows[z];
            walked += curr;
        }
        ans = min(ans, walked);
    }








}
