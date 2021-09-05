class Solution {
public:
    int N;
    struct DSU {
        int count;
        vector<int> parent, size;
        DSU(int M) : count(M), parent(M, -1), size(M, 1) {}
        bool Union(int a, int b) {
            a = Find(a), b = Find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            --count;
            return true;
        }
        int Find(int a) {
            if (parent[a] == -1) return a;
            return parent[a] = Find(parent[a]);
        }
    };

    vector<int> sieve(int M) {
        vector<int> spf(M+1);
        spf[0] = spf[1] = -1;
        for (int i = 3; i <= M; i += 2) spf[i] = i;
        for (int i = 2; i <= M; i += 2) spf[i] = 2;
        for (int i = 3; i <= M; i += 2) {
            if (spf[i] != i) continue;
            for (auto j = (long long)i*i; j <= M; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
        return spf;
    }

    unordered_set<int> primeFactors(int x, vector<int>& spf) {
        unordered_set<int> factors;
        while (x != 1) {
            factors.insert(spf[x]);
            x /= spf[x];
        }
        return factors;
    }

    void processGroup(set<int>& indices, vector<int>& nums, unordered_map<int, int>& mp) {
        vector<int> values;
        for (int i : indices) values.push_back(nums[i]);
        sort(values.begin(), values.end());
        int c = 0;  // counter
        for (int i : indices) mp[i] = values[c++];
    }

    bool gcdSort(vector<int>& nums) {
        N = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> spf = sieve(mx);
        unordered_map<int, vector<int>> factorGroups;  // groups by prime factor
        for (int z = 0; z < N; ++z) {
            auto s = primeFactors(nums[z], spf);
            for (int factor : s)
                factorGroups[factor].push_back(z);
        }
        DSU uf{N};
        for (auto& g : factorGroups) {
            vector<int>& indices = g.second;
            int first = indices[0];
            for (int i = 1; i < indices.size(); ++i)
                uf.Union(first, indices[i]);
        }
        unordered_map<int, set<int>> swappableGroups;  // groups of swappable indices
        for (int z = 0; z < N; ++z) {
            int i = uf.Find(z);
            swappableGroups[i].insert(z);
        }
        unordered_map<int, int> mergedMap;  // combine the disjoint sets
        for (auto& s : swappableGroups) {
            auto& indices = s.second;  // indices in the group
            processGroup(indices, nums, mergedMap);
        }

        int prev = -1;  // counter, previous value
        for (int z = 0; z < N; ++z) {
            int val = nums[z];
            if (mergedMap.count(z))
                val = mergedMap[z];
            if (prev != -1 && val < prev)
                return false;
            prev = val;
        }
        return true;

    }
};
