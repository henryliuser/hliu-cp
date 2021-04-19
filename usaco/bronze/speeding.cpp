#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);
  int N, M; cin >> N >> M;
  int gridR[100], gridC[100];
  int cursor = 0;
  for (int z = 0; z < N; z++) {
    int len, spd; cin >> len >> spd;
    for (int x = cursor; x < cursor+len; x++) gridR[x] = spd;
    cursor += len;
  }
  cursor = 0;
  for (int z = 0; z < M; z++) {
    int len, spd; cin >> len >> spd;
    for (int x = cursor; x < cursor+len; x++) gridC[x] = spd;
    cursor += len;
  }
  int ans = 0;
  for (int z = 0; z < 100; z++) {
    int diff = gridC[z] - gridR[z];
    if (diff > ans) ans = diff;
  }

  cout << ans << endl;

}
