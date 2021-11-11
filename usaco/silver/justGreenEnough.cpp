#include <bits/stdc++.h>
using namespace std;

int n;

int grid[1000][1000];
int top100[1000][1000];
int topdark[1000][1000];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      top100[k][i] = n;
      topdark[k][i] = n;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
      for (int k = 0; k <= i; k++) {
        if (grid[i][j] == 100) {
          top100[k][j] = min(top100[k][j], i);
        }if (grid[i][j] < 100) {
          topdark[k][j] = min(topdark[k][j], i);
        }
      }
    }
  }
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int toph = n;
      int topd = n;
      for (int c = j; c < n; c++) {
        toph = min(top100[i][c], toph);
        topd = min(topdark[i][c], topd);
        if (toph < topd) {
          tot += topd-toph;
        }
      }
    }
  }

  cout << tot << endl;
}
