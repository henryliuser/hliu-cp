#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define S second
#define F first

string a, b;
map<int, int> cnt;
int ans = 0;
vector<string> out;

int g = 0;
void print(int x, int y, int z, vector<string> &s) {
    g = z; while (g--) s[0].push_back(x + '0');
    g = z; while (g--) s[1].push_back(y + '0');
}

int find(int x, int t, vector<string> &s,
         map<int,int> &a, map<int,int> &b,
         int z = -1)
{
    int c = 0;
    auto it = b.lower_bound(t-x);
    while (a[x] && it != end(b)) {
        int y = it->F;
        int q = min(a[x], it->S);
        if (z == -1) q = 1;
        a[x] -= q;
        if ( !(b[y] -= q) ) b.erase(y);
        it = b.lower_bound(t-x);
        print(x, y, q, s);
        if (z == -1) return 1;
        c += q;
    }
    return c;
}

void solve(int a0, map<int, int> &u) {
    auto mp = cnt;
    vector<string> s(2);

    if (!find(a0, 10, s, u, mp, 1)) return;
    int carries = 1;

    for (auto &p : u)
        carries += find(p.F, 9, s, u, mp);

    int z = mp[9];
    carries += z;
    mp.erase(9);
    while (z--) s[1].push_back('9');

    if (carries <= ans) return;

    ans = carries;
    for (int i = 9; i; --i) {
        while (u[i]--)  s[0].push_back(i + '0');
        while (mp[i]--) s[1].push_back(i + '0');
    }
    out = s;
}

bool flip = false;
void solve() {
    cin >> a >> b;
    if (a.size() > b.size()) {
        flip = true;
        swap(a, b);
    }

    map<int, int> u;
    for (char c : a) ++u[c-'0'];
    for (char c : b) ++cnt[c-'0'];
    out = {a,b};

    for (auto &p : u) {
        auto s = u;
        solve(p.F, s);
    }

    for (int j = 0; j < 2; ++j) {
        int i = (flip) ? !j : j;

        reverse(begin(out[i]), end(out[i]));
        cout << out[i] << "\n";
    }
}

int main() {
    solve();
}
