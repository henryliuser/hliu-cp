#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct section {
  string type;
  int lo, hi; // range
  section(string t, int l, int h): type(t), lo(l), hi(h) {
    if (t == "off") {lo = -1*h; hi = -1*l; type = "on";}
  }
  void combine(int l, int h) {
    if (type == "none") {lo = max(lo, l); hi = min(hi, h);}
    else {lo += l; hi += h;}
  }
};

int main() {
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
  int N; cin >> N;

  vector<section> sequence;
  section* prev;
  for (int a = 0; a < N; a++) {
    string type; cin >> type;
    int lo, hi; cin >> lo >> hi;
    if (sequence.size() == 0 || (*prev).type != type ) {
        section s(type, lo, hi);
        sequence.push_back(s);
    }
    else {
        if ((*prev).type == type) (*prev).combine(lo, hi);
    }
      prev = &sequence.back();
  }
  int first_idx = -1;
  for (int a = 0; a < sequence.size(); a++) {
    section s = sequence[a];
    if (s.type == "none") {first_idx = a; break;}
  }
  section right = sequence[first_idx];
  section left(right.type, right.lo, right.hi);
  for (int a = first_idx-1; a >= 0; a--) {
    section r = sequence[a];
    left.hi -= r.lo; left.lo -= r.hi;
  }
  for (int a = first_idx+1; a < sequence.size(); a++) {
    section r = sequence[a];
    if (r.type == "on") {right.hi += r.hi; right.lo += r.lo;}
    if (r.type == "none") right.combine(r.lo, r.hi);
  }
  left.hi = max(left.hi,0); left.lo = max(left.lo,0);
  right.hi = max(right.hi,0); right.lo = max(right.lo,0);
  cout << left.lo << " " << left.hi << endl;
  cout << right.lo << " " << right.hi << endl;

}
