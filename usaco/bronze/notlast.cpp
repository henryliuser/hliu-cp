#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool sortMap(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main() {
  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);
  int N; cin >> N;
  map<string, int> counts = {
    {"Bessie",0}, {"Elsie",0}, {"Daisy",0}, {"Gertie",0},
    {"Annabelle",0}, {"Maggie",0}, {"Henrietta",0}
  };
  for (int a = 0; a < N; a++) {
      string cow; int amt; cin >> cow >> amt;
      counts[cow] += amt;
  }
  vector<pair<string, int>> temp;
  for (auto it : counts) temp.push_back(it);
  sort(temp.begin(), temp.end(), sortMap);
//  int minAmt = counts.begin()->second;
  int minAmt = temp.begin()->second;
  bool found = false;
  pair<string, int> ans("", -1);
  for (auto i : temp) {
      if (!found && i.second > minAmt) {
          found = true;
          ans.second = i.second;
          ans.first = i.first;
          continue;
      }
      else if (found && i.second == ans.second) { cout << "Tie" << endl; break; }
      if (found) {cout << ans.first << endl; break;}
  }
  if (!found) cout << "Tie" << endl;
}
