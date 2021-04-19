#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

int main() {
   // /Users/henryliu/Desktop/usaco/clion/bronze/
  freopen("sleepy.in", "r", stdin);
  freopen("sleepy.out", "w", stdout);
  int N; cin >> N;
  int ans = N-1;
  vector<int> grid(N);
  for (int a = 0; a < N; a++) cin >> grid[a];
  for (int a = N-2; a >= 0; a--) {
    if (grid[a] < grid[a+1]) ans--;
    else break;
  }
  cout << ans << endl;


}
