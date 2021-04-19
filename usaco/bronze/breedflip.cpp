#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

int main() {
    // /Users/henryliu/Desktop/usaco/clion/bronze/breedflip.in
  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);
  int N; cin >> N;
  string A, B; cin >> A >> B;
  int ans = 0;
  bool last = false;
  for (int a = 0; a < N; a++) {
      if (A[a] != B[a]) last = true;
      else {if (last) ans++; last = false;}
  }
  cout << ans << endl;

}
