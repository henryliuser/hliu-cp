#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int count = 0;
    unordered_map<int, int> parent, size;
    void add(int a) {
        if (size.count(a)) return;
        parent[a] = -1;
        size[a] = 1;
        ++count;
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return 0;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        --count;
        return 1;
    }
    int find(int a) {
        if (parent[a] == -1) return a;
        return parent[a] = find(parent[a]);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int N, M; cin >> N >> M;
    vector<bool> active(N+1);
    vector<int> closings(N);
    vector<vector<int>> graph(N+1);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < N; ++i)
        cin >> closings[i];

    DSU uf;
    vector<bool> ans(N);
    for (int i = N-1; i >= 0; --i) {
        int x = closings[i];
        active[x] = 1;
        uf.add(x);
        for (int y : graph[x]) {
            if (active[y])
                uf.unite(x,y);
        }
        ans[i] = (uf.count == 1);
    }
    for (int i = 0; i < N; ++i)
        cout << (ans[i] ? "YES" : "NO") << endl;


}
