#include <bits/stdc++.h>
using namespace std;

bool done(string &s) {
    for (int i = 0; i < 9; ++i)
        if (s[i] != (i+1 + '0'))
            return false;
    return true;
}
string hori(string &s, int a) {
    string q = s;
    swap(q[a], q[a+1]);
    return q;
}
string vert(string &s, int a) {
    string q = s;
    swap(q[a], q[a+3]);
    return q;
}

int bfs(string &s) {
    queue<string> q;
    unordered_set<string> seen;
    seen.reserve(362880);  // TLE without this line lol
    if (done(s)) return 0;
    q.push(s);
    int depth = 0;
    while (!q.empty()) {
        ++depth;
        int sz = q.size();
        while (sz--) {
            string x = q.front();
            q.pop();
            if (seen.count(x)) continue;
            seen.insert(x);
            for (int i : {0,1,3,4,6,7}) {
                string y = hori(x, i);
                if (done(y)) return depth;
                q.push(y);
            }
            for (int i : {0,1,2,3,4,5}) {
                string y = vert(x, i);
                if (done(y)) return depth;
                q.push(y);
            }
        }
    }
    return depth;
}

int main() {
    string s = "123456789";
    for (int i = 0; i < 9; ++i) {
        int x; cin >> x;
        s[i] = x + '0';
    }

    cout << bfs(s) << endl;
}
