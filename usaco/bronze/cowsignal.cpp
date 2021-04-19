#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
  int M, N, K; cin >> M >> N >> K;
  for (int r = 0; r < M; r++) {
    char line[N];
    for (int c = 0; c < N; c++) cin >> line[c];
    for (int z = 0; z < K; z++) {
      for (int a = 0; a < N; a++) for (int q = 0; q < K; q++) cout << line[a];
      cout << endl;
    }
  }


}
