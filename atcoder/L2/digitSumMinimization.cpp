// https://atcoder.jp/contests/abc219/tasks/abc219_d
// this question broke me. solution makes sense though.
// ds(A+B) = ds(A) + ds(B) - 9 * carries
// optimal solution structure:
// let a[0] represent right-most digit
// a[0] + b[0] <= 10
// a[1..k] + b[1..k] <= 9
// since the condition is different ONLY for last digit,
// iterate on possibilities of last digit (only 1-9)
// take the best answer.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ans = 0;
string a, b;
vector<int> C[2], cnt[2];
vector<string> out, s;

void add(int x, int y, int z) {
    while (z--) {
        s[0].push_back(x + '0');
        s[1].push_back(y + '0');
    }
}

int find(int x, int t, int z = -1) {
    int c = 0;
    for (int y = t-x; y < 10; ++y) {
        if (!cnt[1][y] || !cnt[0][x]) continue;
        int q = z;
        if (z == -1)
            q = min(cnt[0][x], cnt[1][y]);
        cnt[0][x] -= q;
        cnt[1][y] -= q;
        add(x, y, q);
        if (z != -1 && q > 0) return 1;
        c += q;
    }
    return c;
}

void solve(int a0) {
    cnt[0] = C[0];
    cnt[1] = C[1];
    s.assign(2, "");
    int carry = find(a0, 10, 1);
    if (!carry) return;

    for (int x = 1; x < 10; ++x)
        if (cnt[0][x])
            carry += find(x, 9);

    carry += cnt[1][9];
    while (cnt[1][9]--)
        s[1].push_back('9');
    ++cnt[1][9];

    if (carry <= ans) return;
    ans = carry;
    for (int x = 9; x >= 0; --x)
        for (int j = 0; j < 2; ++j) {
//            if (x == 9 && j == 0)
//                printf("remaining 9's in A: %d\n", cnt[j][x]);
            while (cnt[j][x]--)
                s[j].push_back(x+'0');
        }
    out = s;
}

bool flip = false;
int main() {
    cin >> a >> b;
    for (auto &x : C) x.resize(10);
    if (a.size() > b.size()) {
        swap(a,b);
        flip = true;
    }
    out = {a, b};
    for (char c : a) ++C[0][c-'0'];
    for (char c : b) ++C[1][c-'0'];

    for (int i = 1; i < 10; ++i)
        if (C[0][i])
            solve(i);

    for (int j = 0; j < 2; ++j) {
        int i = (flip) ? !j : j;
        reverse(begin(out[i]), end(out[i]));
        cout << out[i] << "\n";
    }
}
