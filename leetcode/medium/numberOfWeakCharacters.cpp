// O(N log N). Very instructive question.
class Solution {
public:
    int ans = 0;
    multiset<int> currDefs;
    map<int, multiset<int>> remain;  // <def, {atk}> pairs

    void process(int currAtk) {  // check all entries with currAtk
        for (int d : currDefs) {
            remain[d].erase(currAtk);  // first, erase all remaining
            if (remain[d].empty())     // entries with currAtk
                remain.erase(d);
        }
        for (int d : currDefs) {       // then binary search for each defense
            if (remain.lower_bound(d+1) != remain.end())
                ++ans;
        }
        currDefs.clear();
    }

    int numberOfWeakCharacters(vector<vector<int>>& A) {
        int N = A.size();
        sort(A.begin(), A.end());
        for (auto& p : A)
            remain[p[1]].insert(p[0]);
        int currAtk = A[0][0];
        for (auto& p : A) {
            int atk = p[0];
            int def = p[1];
            if (atk != currAtk)
                process(currAtk);
            currDefs.insert(def);
            currAtk = atk;
        }
        process(currAtk);
        return ans;
    }
};
