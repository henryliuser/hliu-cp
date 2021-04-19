#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
  int N; cin >> N;
  map<char, int> ans;
  for (char c = 'a'; c <= 'z'; c++) ans[c] = 0;

  for (int a = 0; a < N; a++) {
      string front, back; cin >> front >> back;
      map<char, int> boardMapF = ans;
      map<char, int> boardMapB = ans;
      for (int b = 0; b < front.length(); b++) boardMapF[front.at(b)] += 1;
      for (int b = 0; b < back.length(); b++) boardMapB[back.at(b)] += 1;
      for (auto it : boardMapF)
          boardMapF[it.first] = max(it.second, boardMapB[it.first]);
      for (auto it : boardMapB)
          ans[it.first] = max(it.second, boardMapF[it.first]);
  }
  for (auto it : ans)
      cout << it.second << endl;


}
