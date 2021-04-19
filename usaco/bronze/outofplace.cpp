#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

int main() {
    // /Users/henryliu/Desktop/usaco/clion/bronze/outofplace.in
  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);
  int N; cin >> N;
  int grid[N];
  int bIdx, bHght;
  int ans = 0;
  for (int z = 0; z < N; z++) {
    int t; cin >> t;
    grid[z] = t;
    if (z > 0 && t < grid[z-1]) {bIdx = z; bHght = t;}
  }
  int cidx = N-1;
//  bool go_left = false;
  for (int z = 0; z < N; z++) {
    if (grid[z] > bHght) {cidx = z+1; break;}
  }

  int lastH;
  if (cidx > bIdx) {
    for (int z = bIdx; z < cidx; z++) {
        int t = grid[z];
      if (lastH != t) ans++;
      lastH = t;
    }
  }
  if (bIdx > cidx) {
    for (int z = bIdx; z > cidx; z--) {
        int t = grid[z];
        if (lastH != t) ans++;
        lastH = t;
    }
  }
  cout << ans << endl;



}
