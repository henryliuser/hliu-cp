// #include <bits/stdc++.h>
#include <algorithm>
#include <tuple>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <utility>
#include <math.h>

#define IN(x, box) box.find(x) != box.end()
using namespace std;

int main() {

    int N; cin >> N;
    vector<int> weights(2*N);
    for (int z = 0; z < 2*N; z++) cin >> weights[z];
    sort(weights.begin(), weights.end());
    vector< tuple<int, int, int> > diffs;
    for (int z = 1; z < 2*N; z++) {
        int d = weights[z] - weights[z-1];
        diffs.push_back( {d, z-1, z} );
    }
    sort(diffs.begin(), diffs.end());
    int ans = 0;
    unordered_set<int> T;
    for (int z = 0; z < N-1; z++) {
        int a = z;
        while (! (IN(diffs[a][1], T) ||
                  IN(diffs[a][2], T) ))
            a++;
        ans += diffs[a][0];
    }


}
