#include <bits/stdc++.h>
using namespace std;

int N, Q;
struct DSU {
    int count;
    vector<bool> rel;
    vector<int> parent, size, src; // Union by Size
    DSU(int N) : count(N), parent(N,-1), size(N, 1), rel(N, 1), src(N, -1) {}
    bool unite(int a, int b, bool attr) { // return on success
        int oa = a, ob = b;
        a = find(a), b = find(b);
        if (a == b) return false; // cycle (undirected)
        bool pa = get(oa), pb = get(ob);
        if (size[a] < size[b]) swap(a, b);
        src[b] = a;
        if (attr && pa!=pb) rel[b] = rel[a];
        if (attr && pa==pb) rel[b] = !rel[a];
        else if (!attr && pa!=pb) rel[b] = !rel[a];
        else rel[b] = rel[a];
        parent[b] = a;
        size[a] += size[b]; // size[b] not used after
        count--;
        return true;
    }
    int find(int v) {
        if (parent[v] == -1) return v;
        return parent[v] = find(parent[v]);
    }
    bool get(int a) {
        if (src[a] == -1) return rel[a];
        return rel[a] == get(src[a]);  // can also compress here probably.
    }
};

string query(DSU &uf) {
    char ch; int a, b;
    cin >> ch >> a >> b;
    if (ch == 'Q') {
        if (uf.find(a) != uf.find(b))
            return "?";
        bool qa = uf.get(a);
        bool qb = uf.get(b);
        return (qa == qb) ? "R" : "A";
    }
    uf.unite(a, b, (ch=='A'));
    return "";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    DSU uf(N+1);
    while (Q--) {
        string res = query(uf);
        if (res == "") continue;
        cout << res << "\n";
    }
}
