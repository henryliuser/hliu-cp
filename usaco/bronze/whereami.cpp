#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);
  int N; cin >> N;
  string str; cin >> str;
  for (int a = 2; a < N; a++) {
      bool found = true;
      unordered_set<string> seen;
      for (int z = 0; z < N-a+1; z++) {
          string sub = str.substr(z, a);
          if (seen.count(sub) > 0) {found = false; break;}
          seen.emplace(sub);
      }
      if (found) {
          cout << a << endl;
          break;
      }
  }


}
