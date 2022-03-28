// https://leetcode.com/problems/word-ladder/
// just bfs
class Solution {
public:
    int ladderLength(string a, string b, vector<string>& words) {
        int N = words.size();
        int K = a.size();
        vector<vector<int>> adj(N+1);
        for (int i = 0; i < N; ++i) {
            string &s = words[i];
            for (int j = i+1; j < N; ++j) {
                string &t = words[j];
                int dx = 0;
                for (int k = 0; k < K; ++k) {
                    bool d = (s[k] != t[k]);
                    if ( (dx += d) > 1) goto bad;
                }
                adj[i].push_back(j);
                adj[j].push_back(i);
                bad: continue;
            }
            int dx = 0;
            for (int k = 0; k < K; ++k) {
                bool d = (s[k] != a[k]);
                if ( (dx += d) > 1 ) goto badA;
            }
            adj[N].push_back(i);
            badA: continue;
        }

        int lvl = 1;
        queue<int> q;
        q.push(N);
        vector<bool> seen(N+1);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int u = q.front();
                seen[u] = 1;
                q.pop();
                for (int v : adj[u]) {
                    if (seen[v]) continue;
                    if (words[v] == b) return ++lvl;
                    q.push(v);
                }
            }
            ++lvl;
        }
        return 0;
    }
};
