#include <bits/stdc++.h>
using namespace std;

int N, M;
int cnt = 0, z = 1;
stack<int> st;
vector<int> id, low, scc;
vector<bool> curr;
vector<vector<int>> graph;

void tarjan(int u) {
    st.push(u);
    curr[u] = 1;
    id[u] = low[u] = cnt++;
    for (int v : graph[u]) {
        if (id[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (curr[v])
            low[u] = min(low[u], id[v]);
    }
    if (id[u] == low[u]) {
        int q = z++;
        while (st.top() != u) {
            scc[st.top()] = q;
            curr[st.top()] = 0;
            st.pop();
        }
        scc[st.top()] = q;
        curr[st.top()] = 0;
        st.pop();
    }

}

void init() {
    scc.resize(N+1);
    graph.resize(N+1);
    id.assign(N+1, -1);
    low.assign(N+1, -1);
    curr.assign(N+1, 0);
}

int main() {
    cin >> N >> M;
    init();
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= N; ++i)
        if (id[i] == -1)
            tarjan(i);
    printf("%d\n", z-1);
    for (int i = 1; i <= N; ++i)
        printf("%d ", scc[i]);
    printf("\n");



}
