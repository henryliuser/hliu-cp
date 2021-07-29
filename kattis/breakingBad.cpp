#include <bits/stdc++.h>
using namespace std;

unordered_set<string> walter, jesse;
unordered_map<string, vector<string>> graph;
void dfs(string s, string last, bool walt) {
    // cout << s << " " << last << " " << walt << endl;
    if (walter.count(s) || jesse.count(s)) throw -1;  // cycle
    if (walt) walter.insert(s);
    else jesse.insert(s);
    for (auto& to : graph[s]) {
        if (to == last) continue;
        dfs(to, s, !walt);
    }
}

int main() {

    int N; cin >> N;
    vector<string> items(N);
    for (int z = 0; z < N; ++z)
        cin >> items[z];
    int M; cin >> M;
    vector<string> starts;
    for (int z = 0; z < M; ++z) {
        string a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (!walter.count(a)) starts.push_back(a);
        walter.insert(a);
        walter.insert(b);
    }
    walter.clear();
    try { for (auto& s : starts) dfs(s, "", true); }
    catch (int x) { return printf("impossible\n"); }
    for (auto& s : items) {
        if (walter.count(s) || jesse.count(s)) continue;
        walter.insert(s);
    }
    for (auto& s : walter) cout << s << " "; cout << endl;
    for (auto& s : jesse)  cout << s << " "; cout << endl;
}
