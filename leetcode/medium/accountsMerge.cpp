class Solution {
public:

    struct DSU {
        int count;
        unordered_map<string, string> parent;
        unordered_map<string, int> size;
        void Add(string a) {
            if (parent.count(a)) return;
            parent[a] = a;
            size[a] = 1;
            count++;
        }
        bool Union(string e1, string e2) {
            Add(e1), Add(e2);
            e1 = Find(e1), e2 = Find(e2);
            if (e1 == e2) return false;
            if (size[e1] < size[e2]) swap(e1, e2);
            parent[e2] = e1;
            size[e1] += size[e2];
            count--;
            return true;
        }
        string Find(string e) {
            if (e == parent[e]) return e;
            return parent[e] = Find(parent[e]);
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU uf;
        vector<vector<string>> ans;
        unordered_map<string, string> m; // email to person
        for (auto& v : accounts) {
            string& name = v[0];
            if (v.size() == 1) ans.push_back(v);
            else {
                string first = v[1];
                uf.Add(first);
                m[first] = name;
                for (int z = 1; z < v.size(); z++) {
                    uf.Union(first, v[z]);
                    m[v[z]] = name;
                }
            }
        }
        unordered_map<string, set<string>> comps;
        for (auto it = m.begin(); it != m.end(); it++) {
            string email = it->first;
            string comp = uf.Find(email);
            comps[comp].insert(email);
        }
        for (auto it = comps.begin(); it != comps.end(); it++) {
            string e = it->first;
            vector<string> person = {m[e]};
            for (string q : it->second) {
                person.push_back(q);
            }
            ans.push_back(person);
        }
        return ans;
    }
};
