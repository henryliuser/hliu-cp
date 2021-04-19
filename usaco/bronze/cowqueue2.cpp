#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main() {
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);
  int N; cin >> N;

  vector<pair<int, int> > cowList;

  for (int a = 0; a < N; a++) {
      int arrival, duration; cin >> arrival >> duration;
      pair<int, int> c = make_pair(arrival, duration);
      cowList.push_back(c);
  }
  sort(cowList.begin(), cowList.end());
  int timeMarker = cowList[0].first + cowList[0].second;
  for (int a = 1; a < N; a++) {
      pair<int, int> it = cowList[a];
      if (it.first < timeMarker) timeMarker += it.second;
      else timeMarker = it.first + it.second;
  }

  cout << timeMarker << endl;

}
