using event = array<int, 2>;  // {height, isStart}
class Solution {
public:
    struct Interval {
        int imax = -1;
        map<int, int> mp;
        void add(int h) {
            ++mp[h];
            imax = max(imax, h);
        }
        void pop(int h) {
            if (--mp[h]) return;
            mp.erase(h);
            imax = mp.rbegin()->first;
        }

    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<event>> E;
        vector<vector<int>> ans;
        for (auto &e : buildings) {
            E[e[0]].push_back( {e[2], 1} );
            E[e[1]].push_back( {e[2], 0} );
        }
        Interval curr;
        curr.add(0);
        for (auto &p : E) {
            int x = p.first;
            int last = curr.imax;
            for (auto &e : p.second) {
                if (e[1]) curr.add(e[0]);
                else      curr.pop(e[0]);
            }
            int h = curr.imax;
            if (h != last)
                ans.push_back( {x,h} );
        }
        return ans;
    }
};
