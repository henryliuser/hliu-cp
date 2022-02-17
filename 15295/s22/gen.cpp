#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define accuracy chrono::steady_clock::now().time_since_epoch().count()
mt19937 rng(accuracy);
int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}

vector<pair<int, int>> gen_tree(int n = 0){
    const int MXN = 1e6+5;
    int permutation[MXN];
    assert(n >= 0);
    vector<pii> res(n ? n - 1 : 0);
    // if you like to have bamboo like tree or star like tree uncomment below 8 lines
    if (rng() % 5 == 0) { // bamboo like tree
      for (int i = 1; i < n; ++i) res[i-1] = {i, i + 1};
      return res;
    }
    if (rng() % 7 == 0) { // star tree
      for (int i = 2; i <= n; ++i) res[i-2] = {1, i};
      return res;
    }
    iota(permutation, permutation + 1 + n, 0);
    shuffle(permutation + 1, permutation + 1 + n, rng);
    for(int i = 2; i <= n; ++i){
      int u = i, v = rand(1 , i-1);
      u = permutation[u], v = permutation[v];
      res[i-2] = minmax(u, v); // u < v, just for convenience while debugging
    }
    shuffle(res.begin() , res.end() , rng);
    return res;
}

int main() {
    int N = 100000;
    freopen("/Users/henryliu/Desktop/hliu-cp/15295/s22/B.out", "w", stdout);
    auto s = gen_tree(N);
    cout << N << '\n';
    for (auto &p : s)
        cout << p.first << " " << p.second << '\n';
}
