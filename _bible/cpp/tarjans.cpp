#include <bits/stdc++.h>
using namespace std;

int N;
int curr = 0;
stack<int> st;
vector<int> id, low;
vector<bool> onStack;
vector<vector<int>> graph;

void dfs(int u) {
    st.push(u);
    onStack[u] = 1;
    id[u] = low[u] = curr++;
    for (int v : graph[u]) {
        if (id[v] == -1) {  // if not visited
            dfs(v, graph);
            low[u] = min(low[u], low[v]);
        }
        else if (onStack[v])  // genius part
            low[u] = min(low[u], id[v]);
    }
    if (low[u] == id[u]) {  // found an SCC
        while (st.top() != u) {
            onStack[st.top()] = 0;
            st.pop();
        }
        onStack[st.top()] = 0;
        st.pop();
    }
}

void tarjan() {
    N = graph.size();
    id.assign(N, -1);
    low.assign(N, -1);
    onStack.assign(N, false);
    for (int i = 0; i < N; ++i)
        if (id[i] == -1)
            dfs(i, graph);
}
