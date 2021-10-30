#include <bits/stdc++.h>
using namespace std;

int N, M;
int s = 0, curr = 0;
stack<int> st;
vector<int> id, low, scc;
vector<bool> onStack, seen;
vector<vector<int>> graph;

void tarjan(int u) {
    st.push(u);
    onStack[u] = 1;
    id[u] = low[u] = ++curr;
    for (int v : graph[u]) {
        if (id[v] == -1) {  // if not visited
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (onStack[v])  // genius part
            low[u] = min(low[u], id[v]);
    }
    if (low[u] == id[u]) {  // found an SCC
        int q = s++;
        while (st.top() != u) {
            onStack[st.top()] = 0;
            scc[st.top()] = q;
            st.pop();
        }
        scc[st.top()] = q;
        onStack[st.top()] = 0;
        st.pop();
    }
}

bool dfs(int u, int v) {
    if (u == v) return 1;
    seen[u] = 1;
    for (int y : graph[u])
        if (!seen[y] && dfs(y, v))
            return 1;
    return 0;
}

void init() {
    graph.resize(++N);
    id.assign(N, -1);
    low.assign(N, -1);
    scc.resize(N);
    onStack.assign(N, false);
    seen.assign(N--, false);
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
    for (int i = 2; i <= N; ++i) {
        if (scc[i] != scc[i-1]) {
            printf("NO\n");
            if (dfs(i-1, i))
                printf("%d %d\n", i, i-1);
            else
                printf("%d %d\n", i-1, i);
            return 0;
        }
    }
    printf("YES\n");
}
