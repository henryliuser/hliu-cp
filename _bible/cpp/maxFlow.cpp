struct MaxFlow {
    struct edge {
        int u, v;
        ll cap, flow, cost;
        struct edge *rev = NULL;
        edge(int from, int to, ll capacity, ll c) {
            u = from; v = to; cap = capacity; flow = 0; cost = c;
        }
    };
 
    int numnodes;
    bool hasnegativecost = false;
    vector<vector<edge*>> g;
    vector<ll> dist;
    vector<ll> phi;
    vector<int> current;
    vector<edge*> parentedge;
    
    MaxFlow(int n) {
        numnodes = n;
        g.resize(numnodes);
        dist.resize(numnodes);
        phi.resize(numnodes);
        current.resize(numnodes);
        parentedge.resize(numnodes);
    }
    ~MaxFlow() {
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                delete g[i][j];
            }
        }
    }
    
    void add_edge(int u, int v, ll cap) {add_edge_internal(u,v,cap,1);}
    void add_edge(int u, int v, ll cap, ll cost) {
        if (cost < 0) hasnegativecost = true;
        add_edge_internal(u,v,cap,cost);
    }
    void add_edge_internal(int u, int v, ll cap, ll cost) {
        struct edge *forward = new struct edge(u,v,cap,cost);
        struct edge *backward = new struct edge(v,u,0,cost);
        forward->rev = backward;
        backward->rev = forward;
        g[u].push_back(forward);
        g[v].push_back(backward);
    }
    
    ll dinic(int source, int sink) {
        ll flow = 0;
        while (true) {
            // 1. build layer graph
            fill(dist.begin(), dist.end(), -1);
            dist[source] = 0;
            bfs(source);
            if (dist[sink] == -1) return flow;
        
            // 2. find blocking flow
            ll f = blockingflow(source, sink);
            flow += f;
        }
        return flow;
    }
    
    void bfs(int source) {
        deque<int> q;
        q.push_back(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop_front();
            for (struct edge *e : g[u]) {
                if (e->cap - e->flow > 0 && dist[e->v] == -1) {
                dist[e->v] = dist[e->u] + 1;
                q.push_back(e->v);
                }
            }
        }
    }
    
    ll blockingflow(int source, int sink) {
        fill(current.begin(), current.end(), 0);
        ll total = 0;
        while (true) {
            ll f = dfs(source, sink);
            if (f == 0) return total;
            total += f;
            int u = source;
            while (u != sink) {
                struct edge *e = g[u][current[u]];
                e->flow += f;
                e->rev->flow -= f;
                u = e->v;
            }
        }
    }
    
    ll dfs(int u, int sink) {
        if (u == sink) return LLONG_MAX;
        while (current[u] < g[u].size()) {
            struct edge *e = g[u][current[u]];
            if (dist[e->v] > dist[e->u] && e->cap - e->flow > 0) {
                ll f = dfs(e->v, sink);
                if (f > 0) return min(f, e->cap-e->flow);
            }
            current[u]++;
        }
        return 0;
    }
    
    pair<ll,ll> mcmf(int source, int sink) {
        if (hasnegativecost) 
            bellman_ford(source);
        else 
            fill(phi.begin(), phi.end(), 0);
    
        ll totalflow = 0;
        ll totalcost = 0;
        while (true) {
        dijkstra(source, sink);
        if (dist[sink] == LLONG_MAX) break;
        // update potentials
        for (int i = 0; i < numnodes; i++) 
            if (dist[i] != LLONG_MAX) 
                phi[i] += dist[i];

        // determine amount of flow to push
        ll minf = LLONG_MAX;
        for (int u = sink; u != source; u = current[u]) 
            minf = min(minf, parentedge[u]->cap - parentedge[u]->flow);

        // push flow
        for (int u = sink; u != source; u = current[u]) {
            parentedge[u]->flow += minf;
            parentedge[u]->rev->flow -= minf;
            totalcost += parentedge[u]->cost * minf;
        }
        totalflow += minf;
        }
    
        return make_pair(totalflow, totalcost);
    }
    
    void bellman_ford(int source) {
        vector<vector<ll>> dp(numnodes, vector<ll>(numnodes, LLONG_MAX));
        fill(dp[source].begin(), dp[source].end(), 0);
        for (int k = 1; k < numnodes; k++) {
            for (int u = 0; u < numnodes; u++) {
                dp[u][k] = dp[u][k-1];
                for (struct edge *e : g[u]) 
                    dp[u][k] = min(dp[u][k], dp[e->v][k-1] + e->cost);
            }
        }
        for (int i = 0; i < numnodes; i++) 
            phi[i] = dp[i][numnodes-1];
    }
    
    void dijkstra(int source, int sink) {
        fill(dist.begin(), dist.end(), LLONG_MAX);
        vector<bool> visited(numnodes, false);
        dist[source] = 0;
        priority_queue<pair<ll,int>> q;
        q.push( {0, source} );
        while (!q.empty()) {
            pair<ll,int> p = q.top();
            q.pop();
            ll currdist = -p.first;
            int u = p.second;
            if (visited[u]) continue;
            visited[u] = true;
            if (u == sink) return;
            for (struct edge *e : g[u]) {
                if (e->flow >= e->cap) continue;
                int v = e->v;
                ll newdist = dist[u] + e->cost + phi[u] - phi[v];
                if (newdist < dist[v]) {
                    dist[v] = newdist;
                    current[v] = u;
                    parentedge[v] = e;
                    q.push(make_pair(-newdist, v));
                }
            }
        }
    }
    
};