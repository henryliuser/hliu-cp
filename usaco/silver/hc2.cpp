#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int,int> pii;

multiset<int> chickens;
vector<pii> cows;
int C, N;

int main(void)
{
  ifstream fin("helpcross.in");
  ofstream fout("helpcross.out");

  fin >> C >> N;
  int x, y, total=0;
  for (int i=0; i<C; i++) { fin >> x; chickens.insert(x); }
  for (int i=0; i<N; i++) { fin >> x >> y; cows.push_back(pii(y,x)); }
  sort (cows.begin(), cows.end());
  for (int j=0; j<N; j++) {
    auto which_chicken = chickens.lower_bound(cows[j].second);
    if (which_chicken != chickens.end() && *which_chicken <= cows[j].first) {
      total++;
      chickens.erase(which_chicken);
    }
  }
  fout << total << "\n";
  return 0;
}
