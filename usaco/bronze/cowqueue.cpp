#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

bool sortPair(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

queue<pair<int, int>> q_sort(queue<pair<int, int>> q) {
    vector<pair<int, int>> temp;
    while (!q.empty()) {temp.push_back(q.front()); q.pop();}
    sort(temp.begin(), temp.end(), sortPair);
    queue<pair<int, int>> ret;
    for (auto it : temp) ret.push(it);
    return ret;
}


int main() {
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);
  int N; cin >> N;

  vector<pair<int, int>> cowList;

  for (int a = 0; a < N; a++) {
      int arrival, duration; cin >> arrival >> duration;
      pair<int, int> c = make_pair(arrival, duration);
      cowList.push_back(c);
  }
  sort(cowList.begin(), cowList.end());
  int timeMarker = cowList[0].first + cowList[0].second;
  queue<pair<int, int>> q;
  for (int a = 1; a < N; a++) {
      pair<int, int> it = cowList[a];
      if (it.first <= timeMarker) q.push(it);
      else if (q.empty()){
          timeMarker = it.first + it.second;
      }
      else {
          q = q_sort(q);
          timeMarker = q.front().first + q.front().second;
          q.pop();
      }
  }
  while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      timeMarker += p.second;
  }
  cout << timeMarker << endl;

}
